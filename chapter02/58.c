/**
编写过程is_litter_endian, 当在小端法机器上编译和运行时返回1, 在大端法机器
上编译运行时则返回0. 这个程序应该可以运行在任何机器上, 无论机器的字长是多少. 
 */
#include <stdio.h>

int is_litter_endian(){
    int i = 1;
    return *(char *)&i;
}

int main(){
    printf("%d\n", is_litter_endian());
}
