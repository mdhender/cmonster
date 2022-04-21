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


// PRNG: sourced from https://burtleburtle.net/bob/rand/smallprng.html.


#include <stdint.h>

#include "prng.h"


#define rot(x, k) (((x)<<(k))|((x)>>(32-(k))))


// prng returns a random 64-bit integer based on the given context.
uint64_t prng(prngContext *x) {
    uint64_t e = x->a - rot(x->b, 27);
    x->a = x->b ^ rot(x->c, 17);
    x->b = x->c + x->d;
    x->c = x->d + e;
    x->d = e + x->a;
    return x->d;
}

// prngInit initializes a context using the seed.
void prngInit(prngContext *x, uint64_t seed) {
    x->a = 0xf1ea5eed, x->b = x->c = x->d = seed;
    for (uint64_t i = 0; i < 20; ++i) {
        (void) prng(x);
    }
}
