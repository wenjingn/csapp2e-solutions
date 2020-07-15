/**
写出函数fiveeighths的代码, 对于整数参数x, 计算x/8*5的值, 向零舍入. 它不会溢出. 
函数应该遵循位级整数编码规则.
 */
#include <assert.h>

/* Assume int w = 32 */
int fiveeights(int x){
    int q = x >> 3;
    int r = x & 7;
    
    int qm5 = (q<<2) + q;
    int rm5 = (r<<2) + r;
    x>>31 && (rm5 += 7);
    return qm5 + (rm5>>3);
}

int main(){
    assert(fiveeights(15) == 9);
    assert(fiveeights(7) == 4);
    assert(fiveeights(-7) == -4);
    assert(fiveeights(-15) == -9);
}
