/**
编写C表达式产生如下位模式, 其中a^n表示符号a重复n次. 假设一个w位的数据类型. 你的
代码可以包含对参数m和n的引用, 它们分别表示m和n的值, 但是不能使用表示w的参数.
A. 1^(w-n)0^n
B. 0^(w-n-m)1^n0^m
 */
#include <assert.h>

#define A(n) (-1<<(n))
#define B(n, m) ((~(-1<<(n)))<<m)

int main(){
    assert(A(8) == 0xffffff00);
    assert(B(16, 8) == 0x00ffff00);
}
