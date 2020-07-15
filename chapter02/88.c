#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void test_A(){
    int exp[7] = {24, 25, 26, 27, 28, 29, 30};
    int i;
    int x;
    for (i = 0; i < 7; i++) {
        x = (1<<exp[i])+1; /* 产生一个浮点域中不存在的整数 */
        assert(!((double)(float)x == (double)x));

        x = (1<<exp[i])+ (1<<i+1); /* 产生一个浮点域中存在的整数 */
        assert((double)(float)x == (double)x);
    }
}

void test_B(){
    int x = 0x7fffffff;
    int y = 0x1;
    double dx = (double)x;
    double dy = (double)y;
    assert(!(dx+dy == (double)(x+y)));
}

void test_E(){
    double dx = 0;
    double dy = 0;
    assert(!(dx/dx == dy/dy));
}

void test_d(double dx, double dy, double dz){
    if (!(dx*dy*dz == dz*dy*dx)) {
        printf("{dx:%f, dy:%f, dz:%f} => \nxyz:%f\nzyx:%f\n",
            dx, dy, dz, dx*dy*dz, dz*dy*dx
            );
        abort();
    }
}

void test_D(){
    long long int x, y, z;
    int stepx = 49991, stepy = 49993, stepz = 49999;
    for (x = INT_MIN; x < INT_MAX; x+=stepx) {
        for (y = INT_MIN; y <= INT_MAX; y+=stepy) {
            for (z = INT_MIN; z <= INT_MAX; z+= stepz) {
                test_d(x, y, z);
            }
            printf("{x:0x%x, y:0x%x} passed\n", (int)x, (int)y);
        }
    }
}

int main(){
    test_A();
    test_B();
    test_E();
    int x = 0x7fff8010;
    int y = 0x7fff8100;
    int z = 0x7fff800f;
    test_d(x, y, z);
}
