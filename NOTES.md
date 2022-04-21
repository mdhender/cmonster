# Notes

Notes to other who may inherit this program:

    Change all occurances in this file of dolpher to the account which
    you will use for maintenance of this program.  That account will
    have special administrative powers.

    This program uses several data files.  These files are in a directory
    specified by the variable root in procedure init.  In my implementation,
    I have a default ACL on the directory allowing everyone READ and WRITE
    access to the files created in that directory.  Whoever plays the game
    must be able to write to these data files.

Written by Rich Skrenta, 1988.

# Brief Program Organization Overview

## Monster's Shared Files

Monster uses several shared files for communication.
Each shared file is accessed within Monster by a group of 3 procedures of the form: `getX`, `freeX` and `putX`.

`getX` takes an integer and attempts to get and lock that record from the appropriate data file.
If it encounters a "collision", it waits a short random amount of time and tries again.
After `maxerr` collisions it prints a deadlock warning message.

If data is to be read but not changed, a `freeX` should immediately follow the `getX` so that other Monster processes can access the record.
If the record is to be written then a `putX` must eventually follow the `getX`.

## Monster's Record Allocation

Monster dynamically allocates some resources such as description blocks and lines and player log entries.
The allocation is from a bitmap.
I chose a bitmap over a linked list to make the multiuser access to the database more stable.
A particular resource (such as log entries) will have a particular bitmap in the file `INDEXFILE`.
A `getindex(I_LOG)` will retrieve the bitmap for it.

Actually allocation and de-allocation is done through the group of functions `alloc_X` and `delete_X`.
If `alloc_X` returns true, the allocation was successful, and the integer parameter is the number of the block allocated.

The top available record in each group is stored in `indexrec`.
To increase the top, the new records must be initially written so that garbage data is not in them and the `getX` routines can locate them.
This can be done with the `addX(n)` group of routines, which add capacity to resources.

## Parsing in Monster

The main parser(s) use a first-unique-characters method to lookup command keywords and parameters.
The format of these functions is `lookup_x(n,s)`.
If it returns true, it successfully found an unambiguous match to string `s`.
The integer index will be in `n`.

If an unambiguating match is needed (for example, if someone makes a new room, the match to see if the name exists shouldn't disambiguate), the group of routines `exact_X(n,s)` are called.
They function similarly to `lookup_x(n,s)`.

The customization subsystems and the editor use very primitive parsers which only use first character match and integer arguments.

## Asynchronous events in Monster

When someone comes into a room, the other players in that room need to be notified, even if they might be typing a command on their terminal.

This is done in a two part process (producer/consumer problem):

When an event takes place, the player's Monster that caused the event makes a call to `log_event`.
Parameters include the slot of the sender (which person in the room caused the event), the actual event that occurred (`E_something`) and parameters.
Log_event works by sticking the event into a circular buffer associated with the room (room may be specified on `log_event`).

Note: there is not an event record for every room; instead, the event record used is `ROOM # mod ACTUAL NUMBER of EVENT RECORDS`.

The other half of the process occurs when a player's Monster calls `grab_line` to get some input.
`grab_line` looks for keystrokes, and if there are none, it calls `checkevent` and then sleeps for a short time (0.1 - 0.2 seconds).
`checkevent` loads the event record associated with this room and compares the player's buffer pointer with the record's buffer pointer.
If they are different, `checkevent` bites off events and sends them to `handle_event` until there are no more events to be processed.
`checkevent` ignores events logged by its own player.
