/**
编写一个函数 int_shift_are_logical(), 在对int类型的数使用逻辑右移的机器上
运行时, 这个函数生成1, 而其他情况下生成0. 你的代码应该可以运行在任何字长的机器
上. 在几种机器上测试你的代码. 
 */
#include <stdio.h>

int int_shift_are_logical(){
    int x = -1;
    return x>>1 != -1;
}

int main(){
    printf("%d\n", int_shift_are_logical());
}
