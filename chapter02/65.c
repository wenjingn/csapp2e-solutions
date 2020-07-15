/**
写出代码实现如下函数:
# Return 1 when x contains an even number of 1s; 0 otherwise. Assume w=32 #
int even_ones(unsigned x);
 */
#include <assert.h>

int even_ones(unsigned x){
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return !(x & 1);
}

int main(){
    assert(even_ones(0xf));
    assert(even_ones(0x3));
    assert(!even_ones(0x1));
    assert(!even_ones(0x2));
}
