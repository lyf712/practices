//
// Created by LYF on 2022/9/28.
//


#include <cstring>
#include "stdio.h"
#include "iostream"
using namespace std;

typedef char *char_point;

// start 起始地址
void show_bytes(char_point start, int len) {
    // 小端法
    for (int i = 0; i < len; i++) {
        printf("0x%.2x ", start[i]);
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

void show_float(float x){
    show_bytes((char_point) &x, sizeof(x));// & 引用地址
}

void show_point(char_point *x){
    show_bytes((char_point) &x, sizeof(void *));// & 引用地址
}

void test_bytes() {
//    printf("test_bytes:\n");
//    while (true) {
//        printf("input data:\n");
//        int x;
//        float y;
//        scanf("%d", &x);
//        show_int(x);
//        printf("is to exit>> if it ,please input 0\n");
//        int flag = 1;
//        scanf("%d", &flag);
//        if (flag == 0) {
//            return;
//        }
//    }
}

void test1(){
    // test_bytes();

    // 测试数字
    int intData = 0;
    float floatData = (int )intData;
    char_point  pointData = (char_point) intData;
    show_int(intData);
    show_float(floatData);
    show_point(&pointData);

    // 测试字符串 - ACSII码进行解决 - ‘A’ - 65
    char *str = "ABCD";
    show_bytes(str,strlen(str));
}
// 利用位运算进行交换 不需要第三个存储地址
// a^a = 0
void testSwap(){
    int x=1,y=2;
    //printf("address-x=0x%.2f,y=",&x,&y);
//    show_int(x);
//    show_int(y);
    cout<<&x<<":"<<&y<<endl;
    x = x ^ y;
    y = x ^ y;// y = x ^ y ^ y = x ^ 0 = x
    x = x ^ y;// x = x ^ y ^ x = y ^ 0 = y
    printf("x=%d,y=%d",x,y);
    //printf("address-x=0x%.2f,y=",&x,&y);
//    show_int(x);
//    show_int(y);
    cout<<&x<<":"<<&y<<endl;
    // 数字上的交换
    x = x + y;
    y = x - y;// y = x
    x = x - y;// x = y
    printf("x=%d,y=%d",x,y);
    //printf("address-x=0x%.2f,y=",&x,&y);
//    show_int(x);
//    show_int(y);
    cout<<&x<<":"<<&y<<endl;
}

// 位级运算&逻辑运算 → bool
bool testBool(int x,int y){
    if((x^y)==0)
        return true;
    return false;
}
// 移位操作
void moveBit(){
    // 4 8 16 32;1 0
    // << 向左移位，变大
    // 0000 0010 → 0010 0000
    cout<<(2<<4)<<(2>>4);
}
// 测试int最小值
void testBitVal(){
//    char c = 0;
//    while (c>-200){
//        cout<<c<<endl;
//        c--;
//    }
    short s = 1;
    int last = s;
    while (s>0){
        last = s;
        s++;
    }
    cout<<s<<"至"<<last;
}

int main() {



//    testSwap();
//    int i = 1;
//    // printf("%d",&i);
//    cout<<&i;

//    cout<<testBool(1,1);
//    cout<<testBool(1,2);

//      moveBit();

      testBitVal();
}