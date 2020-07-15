/**
遵循位级浮点编码规则, 实现具有如下原型的函数:

# Compute 2*f. If f is NaN, then return f. #
float_bits float_twice(float_bits f);

对于浮点数f, 这个函数计算2.0*f. 如果f是NaN, 你的函数应该简单地返回f.
测试你的函数, 对参数f可以取的所有2^32个值求值, 将结果与你使用机器的浮点运算得到
的结果相比较.
 */

#include "float_bits.c"

float_bits float_twice(float_bits f){
    unsigned sign = f >> 31;
    unsigned exp  = f >> 23 & 0xff;
    unsigned frag = f & 0x7fffff;

    if (exp == 0xff) {
        return f;
    }

    if (exp == 0xfe) {
        exp = 0xff;
        frag = 0;
    } else if (exp == 0) {
        frag <<= 1;
        exp = frag >> 23;
        frag &= 0x7fffff;
    } else {
        exp++;
    }

    return sign<<31 | exp<<23 | frag;
}

int main(){
    unsigned long long u;
    for (u = 0; u < 4294967296; u++) {
        if (is_nan(u)) {
            assert_bits_equal(float_twice(u), (float_bits)u);
        } else {
            assert_float_equal(b2f(float_twice(u)), 2.0*b2f(u));
        }
    }
}
