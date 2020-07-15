/**
写出代码实现如下函数:
# Return 1 when any even bit of x equals 1; 0 otherwise . Assume w=32 #
int any_even_one(unsigned x);
 */
#include <assert.h>

int any_even_one(unsigned x){
    return !!(x&0x55555555);
}
int main(){
    assert(any_even_one(0x1));
    assert(!any_even_one(0x2));
    assert(any_even_one(0x4));
}
