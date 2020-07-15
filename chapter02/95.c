/**
遵循位级浮点编码规则, 实现具有如下原型的函数:

# Compute (float)i #
float_bits float_i2f(int i);

对于参数i, 这个函数计算 (float)i 的位级表示.
测试你的函数, 对参数f可以取的所有2^32个值求值, 将结果与你使用机器的浮点运算得到
的结果相比较.
 */

#include "float_bits.c"

float_bits float_i2f(int i){
    unsigned sign = i>>31 & 1;
    unsigned exp, frag;
    unsigned absi = sign ? -i : i;
    if (absi == 0) {
        return 0;
    }
    int shift = 0;
    while (!(absi&0x80000000)) {
        absi <<= 1;
        shift++;
    }
    absi <<= 1;
    shift++;
    exp = 32-shift+127;
    frag = absi >> 9;
    if (shift < 9) {
        unsigned rest = 1<<9-shift;
        unsigned rest_m = rest >> 1;
        unsigned frag_r = absi>>shift & rest-1;
        unsigned addition;
        if (frag_r > rest_m) {
            addition = 1;
        } else if (frag_r < rest_m) {
            addition = 0;
        } else {
            addition = frag&1 ? 1 : 0;
        }
        frag += addition;
        if (frag >> 23) exp++;
        frag &= 0x7fffff;
    }
    return sign<<31 | exp<<23 | frag;
}

int main(){
    long long i;
    for (i = -2147483648; i < 2147483648; i++) {
        assert_float_equal(b2f(float_i2f(i)), (float)i);
    }
}
