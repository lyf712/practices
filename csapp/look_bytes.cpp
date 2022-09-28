//
// Created by LYF on 2022/9/28.
//


#include "stdio.h"

typedef char *char_point;

// start 起始地址
void show_bytes(char_point start, int len) {
    // 小端法
    for (int i = 0; i < len; i++) {
        printf("%.2x ", start[i]);
    }

    // 大端法
//    for (int i = len-1; i >= 0; i--) {
//        printf("%.2x ", start[i]);
//    }

    printf("\n");
}

void show_int(int x) {
    show_bytes((char_point) &x, sizeof(x));// & 引用地址
}

void test_bytes() {
    printf("test_bytes:\n");
    while (true) {
        printf("input data:\n");
        int x;
        float y;
        scanf("%d", &x);
        show_int(x);
        printf("is to exit>> if it ,please input 0\n");
        int flag = 1;
        scanf("%d", &flag);
        if (flag == 0) {
            return;
        }
    }
}

int main() {
    test_bytes();
}