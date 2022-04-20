# monster
This is `monster`, a multiuser adventure game system where the players create the universe.
Originally written by Rich Skrenta at Northwestern University, 1988.

The original code has no license file, but it has a note in the [readme.txt](http://www.skrenta.com/monster/readme.txt) file:

    You may freely copy, distribute and change Monster as you wish.

My changes are released under the [MIT License](https://opensource.org/licenses/MIT).

# Original Source

This code was pulled from the [VMS Monster to C port](http://www.skrenta.com/monster/monster.c).

    Author: Rich Skrenta <skrenta@rt.com>
    Port Version: Sat Dec 22 20:05:25 PST 2001

## Notes

VMS Monster was originally written in VMS Pascal.
It ran on Northwestern University's VAX in 1988.
See Rick Skrenta's Monster [repository](http://www.skrenta.com/monster/) for more information.

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
