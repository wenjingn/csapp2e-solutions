/**
写出具有如下原型的函数的代码:
#
# Return 1 when x can be represented as an n-bit, 2's complement number;
#        0 otherwise
# Assume 1 <= n <= w
#
int fits_bits(int x, int n);
 */
#include <assert.h>

int fits_bits(int x, int n){
    x >>= n-1;
    return !x||!~x;
}

int main(){
    assert(!fits_bits(0b111, 3));
    assert(fits_bits(0b111, 4));
    assert(fits_bits(0xfffffff8, 4));
    assert(!fits_bits(0xffffffe8, 4));
    assert(fits_bits(0x80000000, 32));
    assert(fits_bits(0x7f000000, 32));
}
