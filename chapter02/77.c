/**
写出具有如下原型的函数的代码:

# Divide by power of two. Assume 0 <= k < w-1 #
int divide_power2(int x, int k);

该函数要用正确的舍入方式计算x/2^k, 并且应该遵循位级整数编码规则.
 */
#include <assert.h>
int divide_power2(int x, int k) {
    int w = sizeof(int) << 3;
    x>>w-1 && (x += (1<<k)-1);
    return x >> k;
}

int main() {
    assert(divide_power2(5, 2) == 1);
    assert(divide_power2(-5, 2) == -1);
    assert(-5/4 == -1);
}
