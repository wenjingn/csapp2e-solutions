/**
分配给你一个任务, 编写一个C函数来计算2^x的浮点表示. 你意识到完成这个任务的最好
办法是直接创建结果的IEEE单精度表示. 当x太小时, 你的程序将返回0.0 当x太大时, 它
会返回+inf. 填写下列代码的空白部分, 以计算出正确的结果. 假设函数u2f返回的浮点值
与它的无符号参数有相同的位表示

float fpwr2(int x) {
    # Result exponent and fraction #
    unsigned exp, frac;
    unsigned u;

    if (x < ______) {
        # Too small. Return 0.0 #
        exp = ______;
        frac = ______;
    } else if (x < ______) {
        # Denormalized result #
        exp = ______;
        frac = ______;
    } else if (x < ______) {
        # Normalized result #
        exp = ______;
        frac = ______;
    } else {
        # Too big. Return +inf #
        exp = ______;
        frac = ______;
    }

    # Pack exp and frac into 32 bits #
    u = exp << 23 | frac;
    # Return as float #
    return u2f(u);
}
 */

#include <assert.h>

float u2f(unsigned u){
    return *(float*)&u;
}

float fpwr2(int x) {
    unsigned exp, frac;
    unsigned u;

    if (x < -149) {
        exp = 0;
        frac = 0;
    } else if (x < -126) {
        exp = 0;
        frac = 1 << (x+149);
    } else if (x < 128) {
        exp = x+127;
        frac = 0;
    } else {
        exp = 0xff;
        frac = 0;
    }

    u = exp << 23 | frac;
    return u2f(u);
}

int main(){
    unsigned long long _62 = 4611686018427387904;
    assert(u2f(0x3f800000) == 1);
    assert(fpwr2(-150) == 0);
    assert(fpwr2(-149) == 1.0/_62/_62/1024/1024/32);
    assert(fpwr2(-127) == 1.0/_62/_62/8);
    assert(fpwr2(-126) == 1.0/_62/_62/4);
    assert(fpwr2(-1) == 0.5);
    assert(fpwr2(0) == 1);
    assert(fpwr2(1) == 2);
    assert(fpwr2(62) == _62);
    assert(fpwr2(127) == 1.0*_62*_62*8);
    assert(fpwr2(128) == (float)1.0*_62*_62*16);
}
