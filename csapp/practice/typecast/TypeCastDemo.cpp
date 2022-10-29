//
// Created by LYF on 2022/10/29.
//

#include "TypeCastDemo.h"
#include "iostream"
#include "../common/rc.h"
void TypeCastDemo::test1(){
    std::cout<<"test 1 ok!"<<std::endl;
}
//https://blog.csdn.net/qq_42944019/article/details/126512081
void TypeCastDemo::test_cast() {
    char* chars="hello";
    for(char p = *chars;p;p=*++chars){
        //printf("%s\n",&p);
        std::cout<<p<<std::endl;
        int char_to_int = (typeof(p)) p;
        std::cout<<char_to_int*10;
        float int_to_float = (float) char_to_int;
        std::cout<<int_to_float;
    }

    // char -> int ; char -> float
    char* ch = "cc";
    int count = 0;
    int cter =1;
    // 转int
    for(char p=*ch;p;p=*++ch){
       if(p<'0'||p>'9')
           break;
       count += cter * ((int)p);
       cter*=10;
    }
    std::cout<<count;
}

void char_to_int(char* chars,int &int_val){
    int count=0;
    for(char p=*chars;p;p=*++chars){
        if( p<'0' || p>'9' )
            break;
        int new_val = (int)p - 48;
        count=count*10+new_val;
    }
    int_val = count;
}
void char_to_float(char* chars,float &float_val){
    int int_part = 0;
    float float_part =0.0;
    bool flag = false;//遇上 '.'
    float float_flag = 0.1;
    for(char p=*chars;p;p=*++chars){
        if( p == '.' ){
            flag = true;
            continue;
        }
        if( p<'0' || p>'9' )
             break;

        int new_val = (int)p - 48;
        if(!flag){// 处理整数部分
            int_part=int_part*10+new_val;
        }else{// 处理小数部分
            float_part=float_part+float_flag*new_val;
            float_flag/=10;
        }
    }
    float_val = (float )int_part+float_part;
}

RC test_char_to_int(){
    char* ch = "100";
    int int_val = 0;
    char_to_int(ch,int_val);
    std::cout<<int_val<<std::endl;

    ch = "cc";
    char_to_int(ch,int_val);
    std::cout<<int_val<<std::endl;

    ch = "1c";
    char_to_int(ch,int_val);
    std::cout<<int_val<<std::endl;

    ch = "c1";
    char_to_int(ch,int_val);
    std::cout<<int_val<<std::endl;
    return RC::SUCCESS;
}

void test_char_to_float(){
    char* ch = "0.1";
    float float_val = 0.0;
    char_to_float(ch,float_val);
    std::cout<<float_val<<std::endl;

    ch = "10.1";
    float_val = 0.0;
    char_to_float(ch,float_val);
    std::cout<<float_val<<std::endl;

    ch = "cc";
    float_val = 0.0;
    char_to_float(ch,float_val);
    std::cout<<float_val<<std::endl;


    ch = "10.5c";
    float_val = 0.0;
    char_to_float(ch,float_val);
    std::cout<<float_val<<std::endl;
}


// int -> float
// int -> char

int main() {
    // test_char_to_int();
    // test_char_to_float();
}