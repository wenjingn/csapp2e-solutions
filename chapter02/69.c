/**
写出具有如下原型的函数的代码:
#
# Do ratating right shift. Assume 0 <= n < w
# Examples when x = 0x12345678 and w = 32:
# n = 4 -> 0x81234567, n = 20 -> 0x45678123
#
unsigned rotate_right(unsigned x, int n);
 */
#include <assert.h>

unsigned rotate_right(unsigned x, int n) {
    int w = sizeof(unsigned) << 3;
    return (x >> n) | ((x << w - n - 1) << 1);
}

int main(){
    assert(rotate_right(0x12345678, 4) == 0x81234567);
    assert(rotate_right(0x12345678, 20) == 0x45678123);
    assert(rotate_right(0x12345678, 0) == 0x12345678);
}
