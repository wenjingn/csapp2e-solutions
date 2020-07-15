/**
写出具有如下原型的函数的代码:
#
# Clear all but least signficant n bits of x
# Examples: x = 0x78abcdef, n = 8 --> 0xef, n = 16 --> 0xcdef
# Assume 1 <= n <= w
#
int lower_bits(int x, int n);
 */

#include <assert.h>

int lower_bits(int x, int n){
    int mask = (2 << n-1) - 1;
    return x&mask;
}

int main(){
    assert(lower_bits(0x78abcdef, 1) == 1);
    assert(lower_bits(0x78abcdef, 8) == 0xef);
    assert(lower_bits(0x78abcdef, 16) == 0xcdef);
    assert(lower_bits(0x78abcdef, 32) == 0x78abcdef);
}
