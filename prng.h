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

// PRNG: sourced from Far Horizons.

#ifndef MONSTER_PRNG_H
#define MONSTER_PRNG_H

#include <stdint.h>


typedef struct prngContext {
    uint64_t a;
    uint64_t b;
    uint64_t c;
    uint64_t d;
} prngContext;


// prng returns a random 64-bit integer based on the given context.
uint64_t prng(prngContext *x);

// prngInit initializes a context using the seed.
void prngInit(prngContext *x, uint64_t seed);

#endif //MONSTER_PRNG_H
