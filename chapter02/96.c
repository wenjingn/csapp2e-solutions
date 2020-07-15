/**
遵循位级浮点编码规则, 实现具有如下原型的函数:

#
# Compute (int)f.
# If conversion causes overflow or f is NaN, return 0x80000000
#
int float_f2i(float_bits f);

对于浮点数f, 这个函数计算 (int)f. 你的函数应该向零舍入. 如果f不能用整数表示 
(例如, 超出表示范围, 或者它是一个NaN), 那么函数应该返回0x80000000.
测试你的函数, 对参数f可以取的所有2^32个值求值, 将结果与你使用机器的浮点运算得到
的结果相比较
 */

#include "float_bits.c"

int float_f2i(float_bits f){
    int i;
    unsigned sign = f >> 31;
    unsigned exp  = f >> 23 & 0xff;
    unsigned frag = f & 0x7fffff;
    int E = exp - 127;
    unsigned M;
    if (E > 30) return 0x80000000;
    if (E < 0) return 0;
    
    M = frag|0x800000;
    if (E > 23) {
        i = M << E-23;
    } else {
        i = M >> 23-E;
    }
    return sign ? -i : i;
}

int main() {
    unsigned long long u;
    int E;
    for (u = 0; u < 4294967296; u++) {
        E = (u>>23&0xff)-127;
        if (E > 30) {
            assert_bits_equal(float_f2i(u), 0x80000000);
        }else {
            assert_bits_equal(float_f2i(u), (int)b2f(u));
        }
    }
}
