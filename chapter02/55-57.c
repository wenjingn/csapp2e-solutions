/**
2.55 在你能够访问的不同机器上, 使用show_bytes(文件show-bytes.c)编译并运行示例代
码. 确定这些机器使用的字节顺序
2.56 试着用不同的示例值来运行show_bytes的代码
2.57 编写程序show_short, show_long和show_double, 它们分别打印类型为short int, 
long int和double的C语言对象的字节表示. 请试着在几种机器上运行
 */
#include "show_bytes.c"

int main(){
    short s = 0x1234;
    long l = 0x12345;
    double d = 1.0;
    show_short(s);
    show_long(l);
    show_double(d);
}
