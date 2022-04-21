// Copyright (c) 2022 Michael D Henderson
//
// Copyright (c) 1988, 2001 Rich Skrenta
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef MONSTER_PORTAGE_H
#define MONSTER_PORTAGE_H

// helpers for portability?

#include <stdint.h>

#include "prng.h"

void bzero(void *s, size_t n);


// the BSD/Linux file lock utilities
// Remove an existing lock held by this process.
#define LOCK_UN 0
// Place an exclusive lock.
// Only one process may hold an exclusive lock for a given file at a given time.
#define LOCK_EX 1
// Place a shared lock.
// More than one process may hold a shared lock for a given file at a given time.
#define LOCK_SH 3

int flock(int fd, int operation);


// drandom returns the next value from the PRNG as a double in the range [0..1)
double drandom(void);

// random returns the next value from the PRNG as an integer.
long int random(void);

// srandom initializes the seed for the PRNG.
void srandom(unsigned int seed);

#endif //MONSTER_PORTAGE_H
