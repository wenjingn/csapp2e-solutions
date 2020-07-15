/**
写一个C表达式, 在下列描述的条件下产生1, 而在其他情况下得到0. 假设x是int类型.
A. x的任何位都等于1
B. x的任何位都等于0
C. x的最高有效字节中的位都等于1
D. x的最低有效字节中的位都等于0
 */
#define ANY_BIT_ONE(x) !~(x)
#define ANY_BIT_ZERO(x) !(x)
#define MSB_ONE(x) !~((int)(x) >> ((sizeof(int)-1)<<3))
#define LSB_ZERO(x) !((x)&0xff)

#include <assert.h>

int main(){
    assert(ANY_BIT_ONE(-1));
    assert(!ANY_BIT_ONE(0xff000000));
    assert(ANY_BIT_ZERO(0));
    assert(!ANY_BIT_ZERO(0xff000000));
    assert(MSB_ONE(0xff000000));
    assert(!MSB_ONE(0x0f000000));
    assert(LSB_ZERO(0xffffff00));
    assert(!LSB_ZERO(0xfffffff0));
}
