/**
假设我们有一个任务: 生成一段代码, 将整数变量x乘以不同的常熟因子K. 为了提高效率,
我们想只用+,-和<<运算. 对于下列K的值, 写出执行乘法运算的C表达式, 每个表达式中最
多使用3个运算.
A. K = 5
B. K = 9
C. K = 30
D. K = -56
 */

#include <assert.h>

#define MUL_5(x) (((x)<<2)+(x))
#define MUL_9(x) (((x)<<3)+(x))
#define MUL_30(x) (((x)<<5)-((x)<<1))
#define MUL__56(x) (((x)<<3)-((x)<<6))

int main(){
    assert(MUL_5(1) == 5);
    assert(MUL_9(1) == 9);
    assert(MUL_30(1) == 30);
    assert(MUL__56(1) == -56);
    
    assert(MUL_5(7) == 35);
    assert(MUL_9(7) == 63);
    assert(MUL_30(7) == 210);
    assert(MUL__56(7) == -392);

    assert(MUL_5(0) == 0);
    assert(MUL_9(0) == 0);
    assert(MUL_30(0) == 0);
    assert(MUL__56(0) == 0);
    
    assert(MUL_5(-1) == -5);
    assert(MUL_9(-1) == -9);
    assert(MUL_30(-1) == -30);
    assert(MUL__56(-1) == 56);
    
    assert(MUL_5(-7) == -35);
    assert(MUL_9(-7) == -63);
    assert(MUL_30(-7) == -210);
    assert(MUL__56(-7) == 392);
}
