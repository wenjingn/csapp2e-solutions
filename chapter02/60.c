/**
假设我们将一个w位的字中的字节从0到w/8-1编号. 写出下面C函数的代码, 它会返回
一个无符号值, 其中参数x的字节i被替换成字节b:
unsigned put_byte(unsigned x, unsigned char b, int i);
以下示例,说明了这个函数如何工作:
put_byte(0x12345678, 0xab, 2) --> 0x12ab5678
put_byte(0x12345678, 0xab, 0) --> 0x123456ab
 */
#include <assert.h>

unsigned put_byte(unsigned x, unsigned char b, int i){
    int w = i << 3;
    return (x & ~(0xff<<w)) | (b << w);
}

int main(){
    assert(put_byte(0x12345678, 0xab, 2) == 0x12ab5678);
    assert(put_byte(0x12345678, 0xab, 0) == 0x123456ab);
}
