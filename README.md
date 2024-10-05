# monster
This is `monster`, a multiuser adventure game system where the players create the universe.
Originally written by Rich Skrenta at Northwestern University, 1988.

The original code has no license file, but it has a note in the [readme.txt](https://web.archive.org/web/20160212080519/http://www.skrenta.com/monster/readme.txt) file:

    You may freely copy, distribute and change Monster as you wish.

My changes are released under the [MIT License](https://opensource.org/licenses/MIT).

# Original Source

This code was pulled from the [VMS Monster to C port](https://web.archive.org/web/20160212080519/http://www.skrenta.com/monster/monster.c).

    Author: Rich Skrenta <skrenta@rt.com>
    Port Version: Sat Dec 22 20:05:25 PST 2001

## Original Pascal Version Notes

This is README.TXT for Monster, a multiplayer adventure game for VMS.
Monster was written by Rich Skrenta at Northwestern University.

You may freely copy, distribute and change Monster as you wish.
Let me know if you get it up and running, and if you change it, just because I'm interested.
Send mail to `skrenta@nuacc.acns.nwu.edu` or `skrenta@nuacc.bitnet`.

Monster was written in VMS Pascal under VMS 4.6.
It uses file sharing and record locking for communication.
Outside of that, it doesn't do anything tricky.
However, after playing around with a VMS 4.2 system, I have doubts if it will work on a system that old.
If you've got a reasonably recent version of VMS and a Pascal compiler, you shouldn't have any problems.

The Monster source is in two files:
a short one, approx 300 lines, called guts.pas, and a big one, mon.pas, approx 10,000 lines.
The compiled program contains everything necessary to create and maintain the Monster universe.
There is no separate maintenance program.
Instead, a specific person in the game has privileges, and is known as the "Monster Manager".
The MM can do system maintenance while playing, and other players can even observe his work.

Credit for the work to convert GUTS.PAS to a more portable form goes to

     Michael "the spide" Young   MCY1580@RITVAX.BITNET
     Chris "siouxane" Meck       CLM4346@RITVAX.BITNET

Many thanks to them for solving this sticky problem!

Rich Skrenta
November, 1988.

## Original C Version Notes

VMS Monster was originally written in VMS Pascal.
It ran on Northwestern University's VAX in 1988.
See Rick Skrenta's Monster [repository](https://web.archive.org/web/20160212080519/http://www.skrenta.com/monster/) for more information.

This is a more-or-less straight port of the VMS program, and as such uses shared files for IPC between monster clients.
Users must have an account on the local machine.
Each runs a separate copy of the program.
Each client spins looking at the shared files for communication;
short sleeps are used in the line parser to avoid excessively slowing down the system.

## Installation Instructions

If you want to install `monster` for shared use on a Linux system,

1. Set the `#define` for `root` to point to the shared file directory
1. Set the `#define` for `MONSTER_FILE` to be 0660
1. Install monster `setuid` or `setgid` to give it access to the files in the shared directory

The `monster` program will automatically create the proto database the first time its run.
You can type `rebuild` at the first prompt to re-create the database if necessary.
