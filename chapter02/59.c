/**
编写一个C表达式, 使它生成一个字, 由x的最低有效字节和y中剩下的字节组成. 对
于运算数x=0x89ABCDEF和y=0x76543210, 就得到0x765432EF.
 */

#include <assert.h>

#define LSB_OR_MSBS(x, y) ((x)&0xff)|((y)&~0xff)

int main(){
    int x = 0x89abcdef;
    int y = 0x76543210;
    assert(LSB_OR_MSBS(x, y) == 0x765432ef);
}
