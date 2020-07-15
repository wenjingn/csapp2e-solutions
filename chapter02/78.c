/**
写出函数mul5div8的代码, 对于整数参数x, 计算5*x/8, 但是要遵循位级整数编码规则. 
你的代码计算5*x也会产生溢出.
 */
#include <assert.h>

/* Assume int w = 32 */
int mul5div8(int x){
    int mul5 = (x << 2) + x;
    mul5 >> 31 && (mul5 += 7); 
    return mul5 >> 3;
}

int main(){
    assert(mul5div8(7) == 4);
    assert(mul5div8(-7) == -4);
}
