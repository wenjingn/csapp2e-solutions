/**
写出具有如下原型的函数的代码:

# Addition that saturates to TMin or TMax #
int saturating_add(int x, int y);

同正常的补码加法溢出的方式不同, 当正溢出时, saturating_add返回TMax, 负溢出时， 
返回TMin. 这种运算常常用在执行数字信号处理的程序中.
 */

#include <assert.h>

int saturating_add(int x, int y){
    int sum = x+y;
    int sig = 1 << (sizeof(int)<<3)-1;
    int pos_ovf = !(x&sig) && !(y&sig) && sum&sig;
    int neg_ovf = x&sig && y&sig && !(sum&sig);
    
    pos_ovf && (sum = ~sig) || neg_ovf && (sum = sig);
    return sum;
}

int main(){
    assert(saturating_add(0x7ffffffd, 1) == 0x7ffffffe);
    assert(saturating_add(0x80000002, -1) == 0x80000001);
    assert(saturating_add(0x7ffffffd, 2) == 0x7fffffff);
    assert(saturating_add(0x80000002, -2) == 0x80000000);
    assert(saturating_add(0x7ffffffd, 3) == 0x7fffffff);
    assert(saturating_add(0x80000002, -3) == 0x80000000);
}
