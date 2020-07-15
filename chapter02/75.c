/**
假设我们想要计算x*y的完整的2w位表示, 其中, x和y都是无符号数, 并且运行在数据类型
unsigned是w位的机器上. 乘积的低w位能够用表达式x*y计算, 所以我们只需要一个具有下
列原型的函数:

int signed_high_prod(int x, int y);

这个函数计算无符号变量x*y的高w位.
我们使用一个具有下面原型的库函数:

unsigned unsigned_high_prod(unsigned x, unsigned y);

它计算在x和y采用补码形式的情况下, x*y的高w位. 编写代码调用这个过程, 以实现用无
符号数为参数的函数. 验证你的解答的正确性.

-------------------------------------------------------------------------------

论证:
x→, y→ 是w位长度的位向量, 从低位到高位下标依次为0到w-1, 用x→[k]表示向量第k位
X = B2Uw(x→) Y = B2Uw(y→) 是这些位模式表示的无符号值.
x = B2Tw(x→) y = B2Tw(y→) 是这些位模式的补码值.
我们有:
x = X - x→[w-1]*2^w
y = Y - y→[w-1]*2^w

x*y = (X - x→[w-1]*2^w)(Y - y→[w-1]*2^w)
    = X*Y - (x→[w-1]*Y + y→[w-1]*X)*2^w + x→[w-1]*y→[w-1]*2^(2*w)

现在我们要把x*y扩展到2*w位, 即是 乘积x*y模2^(2*w)
(x*y)mod2^(2*w)
    = (X*Y - (x→[w-1]*Y + y→[w-1]*X)*2^w + x→[w-1]*y→[w-1]*2^(2*w))mod2^(2*w)
    = (X*Y)mod2^(2*w) - (x→[w-1]*Y + y→[w-1]*X)*2^w mod2^(2*w)
由此得出: x*y低w位与X*Y相同, 高w位等于X*Y的高w位减 x→[w-1]*Y + y→[w-1]*X

-------------------------------------------------------------------------------

题外: 虽然可以通过把unsigned扩展至unsigned long long作乘法再右移32位取得高位
但是还是有了下面的方法.
把w位2进制数x,y 拆分成左w/2位和右w/2位, 现在我们把x和y看作2^(w/2)进制数
我们现在进行的是2^(w/2)进制的2位数乘法, 不是我们熟悉的2进制8进制10进制16进制:)
这是函数 unsigned_high_prod, signed_high_prod2 的核心思想

[2^(w/2)进制乘法]
x现在由x_l, x_r组成. 其中x_l, x_r是2^(w/2)进制数, x_l为高位, x_r为低位
y现在由y_l, y_r组成. 其中y_l, y_r是2^(w/2)进制数, y_l为高位, y_r为低位
x = x_l*2^(w/2)+x_r, y = y_l*2^(w/2)+y_r
p = x*y = (x_l*2^(w/2) + x_r)*(y_l*2^(w/2) + y_r)
        = (x_l*y_l)*2^w + (x_l*y_r +x_r*y_l)*2^(w/2) + x_r*y_r
设 xy_l = x_l*y_l
   xy_m = x_l*y_r+x_r*y_l
   xy_r = x_r*y_r
p宽度2*w位, 设高w位为p_l, 低w位为p_r

下图是多项式系数xy_l, xy_m, xy_r在位模式下的分布, 以及和p_l, p_r的关系
|<------w/2----->|<------w/2----->|<------w/2----->|<------w/2----->|
                                  |<--------- xy_r (w位) ---------->|
                                   **************** ****************
               |<-----------xy_m(w+1位)----------->|
                * **************** ****************
|<-----------xy_l(w位)----------->|
 **************** **************** 
|<-------------p_l--------------->|<--------------p_r-------------->|

由此得出:
p_r = ((xy_mid << w/2) + xy_right) mod 2^w
p_r与xy_m存在溢出可能.
记为pr_ovf, xy_m_ovf
pr_ovf = p_r < xy_r
xy_m_ovf = xy_m < x_l*y_r
p_l = (xy_l + (xy_m >> w/2) + (xy_m_ovf << w/2) + pr_ovf) mod 2^w
    
signed_high_prod2与unsigned_high_prod的区别
我们始终把数右边的一半看作一个正数所以它可以是无符号的, 如x_r, y_r, xy_r, p_r
即使左边一半有可能是负数, 但我们做算术右移可以保持位值不变.
p_r溢出时和unsigned_high_prod一样处理.
xy_m溢出时则分正溢出负溢出, 有所区别
 */
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    int offset = sizeof(unsigned) << 2;
    int mask = (1<<offset) - 1;
    unsigned x_l = x >> offset;
    unsigned x_r = x & mask;
    unsigned y_l = y >> offset;
    unsigned y_r = y & mask;
    unsigned xlyr = x_l*y_r;
    unsigned xy_m = xlyr + x_r*y_l;
    int xy_m_ovf = xy_m < xlyr;
    unsigned xy_r = x_r*y_r;
    unsigned p_r = (xy_m << offset) + xy_r;
    int pr_ovf = p_r < xy_r;
    return x_l*y_l + (xy_m >> offset) + (xy_m_ovf << offset) + pr_ovf;
}
int signed_high_prod(int x, int y){
    int sig = 1 << (sizeof(int) << 3) - 1;
    int high_prod = unsigned_high_prod(x, y);
    return high_prod - !!(sig&x)*y - !!(sig&y)*x;
}
int signed_high_prod2(int x, int y) {
    int offset = sizeof(int) << 2;
    int sign = 1 << offset+offset-1;
    int mask = (1<<offset) - 1;
    int x_l = x >> offset;
    unsigned x_r = x & mask;
    int y_l = y >> offset;
    unsigned y_r = y & mask;
    
    int xlyr = x_l*y_r;
    int xryl = x_r*y_l;
    int xy_m = xlyr + xryl;
    unsigned xy_r = x_r*y_r;
    unsigned p_r = (xy_m << offset) + xy_r;
    int pr_ovf = p_r < xy_r;
    
    int xy_m_ovf = !(xlyr&sign ^ xryl&sign) && xlyr&sign ^ xy_m&sign;
    xy_m >>= 1;
    xy_m_ovf && (xy_m ^= sign); /* 溢出补全符号位, 对现有符号位取反 */
    return x_l*y_l + (xy_m >> offset-1) + pr_ovf;
}

void test_unsigned_high_prod(){
    unsigned x, y;
    unsigned long long xll, yll;
    int step1 = 233, step2 = 233;
    for (xll = x = 0xffff8837; xll <= UINT_MAX; x+=step1, xll+=step1) {
        printf("testing: x=0x%x ... ", x);
        for (yll = y = 0; yll <= UINT_MAX; y+=step2, yll+=step2) {
            if (unsigned_high_prod(x, y) != xll*yll >> 32) {
                printf("test fail: {x: 0x%x, y: 0x%x} {high(x*y): 0x%x, xll*yll: 0x%llx}\n", 
                        x, y, unsigned_high_prod(x, y), xll*yll);
                abort();
            }
        }
        printf("pass\n");
    }
}

void test_signed_high_prod(int (*proc)(int, int)){
    int x, y;
    long long xll, yll;
    long long mask = 0xffffffff;
    int step1 = 49943, step2 = 49957;
    for (xll = x = INT_MIN; xll <= INT_MAX; x+= step1, xll+= step1) {
        printf("testing: x=0x%x ... ", x);
        for (yll = y = 0; yll <= INT_MAX; y+=step2, yll+=step2) {
            if (proc(x, y) != xll*yll >> 32) {
                printf("test fail: {x: 0x%x, y: 0x%x} {high(x*y): 0x%x, xll*yll: 0x%llx}\n", 
                        x, y, proc(x, y), xll*yll);
                abort();
            }
        }
        printf("pass\n");
    }
}

int main(){
    test_signed_high_prod(signed_high_prod);
    test_signed_high_prod(signed_high_prod2);
}
