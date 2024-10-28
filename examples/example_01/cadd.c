#include <stdio.h>

float cadd(int, float);

float cadd(int x, float y) {
    float res = x + y;
    printf("In cadd: int %d float %.1f returning %.1f\n", x, y, res);
    return res;
}

// скомпилировать командой (для справки: https://www.opennet.ru/base/dev/shared_lib_intro.txt.html):
// gcc -shared -Wl,-soname,libcadd -o libcadd.so -fPIC cadd.c
