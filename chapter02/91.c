/**
遵循位级浮点编码规则, 实现具有如下原型的函数:
# Compute |f|. If f is NaN, then return f. #
float_bits float_absval(float_bits f);

对于浮点数f, 这个函数计算|f|. 如果f是NaN, 你的函数应该简单地返回f.
测试你的函数, 对参数f可以取得所有2^32个值求值, 将结果与你使用机器的浮点运算得到
的结果相比较.
 */

#include "float_bits.c"

float_bits float_absval(float_bits f) {
    if (is_nan(f)) {
        return f;
    }
    return f & 0x7fffffff;
}

int main(){
    unsigned long long u;
    for (u = 0; u < 4294967296; u++) {
        if (is_nan(u)) {
            assert_bits_equal(float_absval(u), u);
        } else if (u>>31) {
            assert_float_equal(b2f((float_absval(u))), -b2f(u));
        } else {
            assert_float_equal(b2f(float_absval(u)), b2f(u));
        }
    }
}
