/**
将下面的C函数补充完整. 函数srl用算术右移(由值xsra给出)来完成逻辑右移, 后面
的其他操作不包括右移或者除法. 函数sra用逻辑右移(由值xsrl给出)来完成算术右移, 后
面的其他操作不包括右移或除法. 可以通过计算8*sizeof(int)来确定数据类型int中的位
数w. 位移量k的取值范围为0~w-1.
int sra(int x, int k){
    int xsrl = (unsigned)x >> k;
    .
    .
    .
}
unsigned srl(unsigned x, int k){
    unsigned xsra = (int)x >> k;
    .
    .
    .
}
 */
#include <assert.h>

int sra(int x, int k){
    int xsrl = (unsigned)x >> k;
    int msbc = 1 << sizeof(int)*8-k-1;
    int mask = msbc - 1;
    int right = xsrl & mask;
    int left = ~(xsrl|mask) + msbc;
    return left+right;
}

unsigned srl(unsigned x, int k){
    int xsra = (int)x >> k;
    int mask = (2 << sizeof(unsigned)*8-k-1)-1;
    return xsra & mask;
}

int main(){
    int x = 0x8f123456;
    assert(sra(x, 4) == 0xf8f12345);
    assert(srl(x, 4) == 0x08f12345);
}
