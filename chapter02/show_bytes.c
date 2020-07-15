#include <stdio.h>

typedef unsigned char *byte_t;
void show_bytes(byte_t b, int n){
    int i;
    printf("0x");
    for(i = 0; i < n; i++){
        printf("%02x", b[i]);
    }
    printf("\n");
}

void show_short(short s){
    show_bytes((byte_t)&s, sizeof(short));
}

void show_int(int i){
    show_bytes((byte_t)&i, sizeof(int));
}

void show_long(long l){
    show_bytes((byte_t)&l, sizeof(long));
}

void show_longlong(long  long ll){
    show_bytes((byte_t)&ll, sizeof(long long));
}

void show_float(float f){
    show_bytes((byte_t)&f, sizeof(float));
}

void show_double(double d){
    show_bytes((byte_t)&d, sizeof(double));
}
