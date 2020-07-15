/**
写出具有如下原型的函数的代码:
# Determine whether substracting arguments will cause overflow #
int tsub_ovf(int x, int y);
如果计算x-y导致溢出, 这个函数就返回1.
 */

#include <assert.h>

int tsub_ovf(int x, int y){
    int diff = x-y;
    int sig = 1 << (sizeof(int)<<3)-1;
    int sig_x = x&sig;
    return sig_x^y&sig && sig_x^diff&sig;
}

int main(){
    assert(!tsub_ovf(1, 0x80000002));
    assert(tsub_ovf(1, 0x80000001));
    assert(!tsub_ovf(-1, 0x7fffffff));
    assert(tsub_ovf(-2, 0x7fffffff));
}
