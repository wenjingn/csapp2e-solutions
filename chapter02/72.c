/**
给你一个任务, 写一个函数, 将整数val复制到缓冲区buf中, 但是只有当缓冲区中有足够
可用的空间时, 才执行复制.
你写的代码如下:

# Copy integer into buffer if space is available #
# WARING: The following code is buggy #
void copy_int(int val, void *buf, int maxbytes) {
    if (maxbytes-sizeof(val) >= 0)
        memcpy(buf, (void *)&val, sizeof(val));
}

这段代码使用了库函数memcpy. 虽然在这里用这个函数有点刻意, 因为我们只是想复制一
个int, 但是它说明了一种复制较大数据结构的常见方法. 
你仔细地测试了这段代码后发现, 哪怕maxbytes很小的时候, 它也能把值复制到缓冲区中.
A. 解释为什么代码中的条件测试总是成功. sizeof运算符返回类型为size_t的值.
B. 你该如何重写这个条件测试, 使之工作正确.
-------------------------------------------------------------------------------

A. 表达式中同时包含有符号和无符号数时, C语言会将有符号数隐式转化为无符号数. 而
无符号数总是大于或等于0的.
 */

#include <assert.h>
#include <string.h>

void copy_int(int val, void *buf, int maxbytes) {
    if (maxbytes >= sizeof(val))
        memcpy(buf, (void *)&val, sizeof(val));
}

int main(){
    char buffer[12];
    void *pointer = buffer;
    int val1 = 1;
    int val2 = 2;
    int val3 = 3;
    
    copy_int(val1, pointer, 12);
    assert(*(int*)pointer == val1);
    pointer += 4;

    copy_int(val2, pointer, 8);
    assert(*(int*)pointer == val2);
    pointer += 4;
    
    copy_int(val3, pointer, 0); /* fail attempt */
    assert(*(int*)pointer != val3);
    copy_int(val3, pointer, 4); /* now copy val3  */
    assert(*(int*)pointer == val3);
    pointer += 4;
}
