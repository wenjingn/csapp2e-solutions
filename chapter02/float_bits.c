#include <stdio.h>
#include <stdlib.h>
#include "float_bits.h"

float b2f(float_bits b){
    return *(float *)&b;
}

int is_nan(float_bits b){
    return (b>>23&0xff) == 0xff && (b&0x7fffff) != 0;
}

void assert_float_equal(float a, float b){
    if (a != b) {
        printf("%x not equal to %x\n", *(unsigned*)&a, *(unsigned*)&b);
        printf("%f not equal to %f\n", a, b);
        abort();
    }
}

void assert_bits_equal(float_bits a, float_bits b){
    if (a != b) {
        printf("%x not equal to %x\n", a, b);
        abort();
    }
}
