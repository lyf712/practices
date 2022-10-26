//
// Created by LYF on 2022/10/27.
//

#include <string>
#include "LangBaseReview.h"
#include "stdio.h"
// 类的实现文件
using namespace std;

void LangBaseReview::non_static_method()  {
    std::string str = "hello";
    printf("i am a static method");
    printf("%s", &str);
}

void LangBaseReview::static_method() {
    printf("i am a static emtho");
}