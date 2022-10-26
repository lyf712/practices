//
// Created by LYF on 2022/10/27.
//
#include "/lang/LangBaseReview.h"

int main(){
    //FIXME ? 文件组织问题No such file or directory
    //    4 | #include "/lang/LangBaseReview.h"
    // CMake配置？
    ::LangBaseReview::static_method();
    LangBaseReview langBaseReview;
    langBaseReview.non_static_method();
}