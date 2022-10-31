//
// Created by LYF on 2022/10/29.
//
#include <sstream>
#include <cmath>
#include "vector"
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

//void float_to_char(float &float_val,char* chars)
//{
//    int int_val = (int)float_val;
//    char* ptr = chars;
//    std::vector<char> vector;
//
//    while (int_val>0){
//        vector.push_back((char) (int_val%10));
//        int_val/=10;
//    }
//    while(!vector.empty()){
//          ptr = vector.data();
//          vector.pop_back();
//          ptr++;
////        *ptr = vector.begin().operator*();
////        ptr++;
////        vector.pop_back();
//    }
//    chars = ptr;
//    //return RC::SUCCESS;
//}

// int -> float
// int -> char

char* float_to_char(float &float_val, char* chars) {
    //int int_val = (int)float_val;
    //sprintf(chars,"%d",int_val);
    std::stringstream ss;
    ss << float_val;
    chars = (char*) ss.str().c_str();
    //std::cout<<chars<<";"<<ss.str().c_str();
    //return RC::SUCCESS;
    return const_cast<char *>(ss.str().c_str());
}


int main() {
    // test_char_to_int();
    // test_char_to_float();
//    std::string str = "hello!string";
//    const char *chars = str.c_str();// const常量？
//    std::cout<<chars;
//    std::cout<<RC::SUCCESS<<std::endl;

    //    char* str = static_cast<char *>(malloc(10 * sizeof(char *)));
//    int year=2002,month=10,day=10;
//    str = "2010-10-07";
//    sscanf(str,"%d-%d-%d",year,month,day);
//    printf("%s",str);
//    printf("%d,%d,%d",year,month,day);

//      float float_val = 37.1;
//      char* chars0= nullptr;
//      float_to_char(float_val,chars0);
//      //std::cout<<chars0<<"ok";
//       std::cout<<"ok"<<chars0;
//    char* str;
//    sprintf(str,"%d",1);
//    std::cout<<str;

//    int a=1111;
//    char *str = nullptr; //[10];
//    str = static_cast<char *>(malloc(4 * sizeof(char)));
//    sprintf(str,"%d",a);
//    // 把整数a转换为字符串，存放在str中
//    printf("str=%s\n",str);
//
//    float b = 110.1;
//    sprintf(str,"%f",b);
//    printf("str=%s\n",str);

//    // 输出str=1111
//    float c = 1.1;
//    size_t MAX_NUM = 20;
//    char *chars = float_to_char(c,NULL);//static_cast<char *>(malloc(2 * sizeof(char)));
//    //float_to_char(c,chars);
//    std::cout<<chars;
//    std::stringstream ss;
//    ss << c;
//    std::cout<<ss.str().c_str();


//      void* value;
//      float* float_val;
//      float_val = (float*) value;


//      float a=0.5;
//      std::cout<<(int)round(a);
    char* chars = (char*) "N23";
    int len = 0;
    int attr_len = 4;
    std::cout<<chars<<std::endl;
    char* data = static_cast<char *>(malloc(attr_len * sizeof(char)));//reinterpret_cast<char *>('1321');
    data =(char*) "abcd";
    //data[0]='1';
    std::cout<<data;

    for (char p = *chars; p; p = *++chars){
//        if(len>=attr_len){
//            realloc(data, sizeof(char));
//        }
       // *(char*)(data+len) = p; //value->data
        data[len] = p;
        len++;
    }
    std::cout<<"ok";
    std::cout<<data;

}