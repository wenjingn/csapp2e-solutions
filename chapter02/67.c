/**
给你一个任务, 编写一个过程int_size_is_32(), 当在一个int是32位的机器上运行
时, 该程序产生1, 而其他情况则产生0. 不允许使用sizeof运算符. 下面是开始时的尝试
int bad_int_size_is_32(){
    int set_msb = 1 << 31;
    int beyond_msb = 1 << 32;
    return set_msb && !beyond_msb;
}
当在 SUN SPARC 这样的32位机器上编译并运行时, 这个过程返回的却是0. 下面的编译器
信息给了我们一个问题的指示:
warning: left shift count >= width of type
A.我们的代码在哪个方面没有遵守C语言标准?
B.修改代码, 使得它在int至少为32位的任何机器上都能正确地运行.
C.修改代码, 使得它在int至少为16位的任何机器上都能正确地运行.
 */

/*
 * A. Standard C99 6.5.7
 *
 * If the value of the right operand is negative or is greater than or equal to
 * the width of the promoted left operand, the behavior is undefined.
 *
 */
#include <stdio.h>

int int_size_is_32_B(){
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

int int_size_is_32_C(){
    int set_msb = (0x8000 << 15) << 1;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

int main(){
    printf("%d %d\n", int_size_is_32_B(), int_size_is_32_C());
}
