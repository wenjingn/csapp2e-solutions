/**
填写下列程序的返回值, 这个程序是测试它的第一个参数是否大于或者等于第二个参数. 
假定函数f2u返回一个无符号32位数字, 其位表示与它的浮点参数相同. 你可以假设两个参
数都不是NaN. 两种0, +0和-0被认为是相等的.

int float_ge(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    # Get the sign bits #
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    # Give an expression using only ux, uy, sx and sy #
    return ______________;
}
 */
#include <assert.h>

unsigned f2u(float f) {
    return *(unsigned *)&f;
}

int float_ge(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    /* Get the sign bits */
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    /* Give an expression using only ux, uy, sx and sy */
    return ux << 1 == 0 && uy << 1 == 0 ||
        !sx && sy ||
        !sx && !sy && ux >= uy ||
        sx && sy && ux <= uy;
}

int main(){
    assert(f2u(1.0) == 0x3f800000);
    assert(f2u(-1.0) == 0xbf800000);
    assert(float_ge(0.0, -0.0));
    assert(float_ge(-0.0, 0.0));
    assert(float_ge(-0.0, -1.0));
    
    assert(float_ge(1.0, -0.0));
    assert(float_ge(1.0, -1.0));
    assert(float_ge(2.1, 1.1));
    assert(float_ge(-1.0, -2.0));

    assert(!float_ge(-1.0, -0.0));
    assert(!float_ge(-1.0, 1.0));
    assert(!float_ge(1.1, 2.1));
}
