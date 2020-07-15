/**
你刚刚开始在一家公司工作, 他们要实现一组过程来操作一个数据结构, 要将4个有
符号字节封装成一个32位unsigned. 一个字中的字节从0 (最低有效位) 编号到3 (最高有
效字节). 分配给你的任务是: 为一个使用补码运算和算术右移的机器编写一个具有如下原
型的函数:

# Declaration of data type where 4 bytes are packed into an unsigned #
typedef unsigned packed_t;
# Extract byte from word. Return as signed integer #
int xbyte(packed_t word, int bytenum);

也就是说, 函数会抽取出指定的字节, 再把它符号扩展为一个32位int.
你的前任 (因为水平不够高而被解雇了) 编写了下面的代码:

# Failed attempt at xbyte #
int xbyte(packed_t word, int bytenum)
{
    return (word >> (bytenum << 3)) & 0xff;
}

A. 这段代码错在哪里?
B. 给出函数的正确实现, 只能使用左右移位和一个减法.
------------------------------------------------------------------------------

A. 这段代码不能得到负数

 */
#include <stdio.h>
#include <assert.h>
typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum) {
    int size = sizeof(packed_t);
    int lshift = size-bytenum-1 << 3;
    int rshift = size-1 << 3;
    return ((int)word << lshift) >> rshift;
}

int main(){
    packed_t word = 0x8f7f00ff;
    assert(xbyte(word, 0) == 0xffffffff);
    assert(xbyte(word, 1) == 0x00000000);
    assert(xbyte(word, 2) == 0x0000007f);
    assert(xbyte(word, 3) == 0xffffff8f);
}
