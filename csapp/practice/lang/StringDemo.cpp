//
// Created by LYF on 2022/10/29.
//

#include <cstring>
#include "StringDemo.h"
#include "iostream"
int ignore_case_strcmp(const char* s1,const char* s2)
{
    if(NULL == s1 || NULL == s2){
        return -1;
    }
    char ch1 = '\0',ch2='0';
    int len1=strlen(s1),len2= strlen(s2);
    if(len1!=len2){
        return -1;
    }
    while(len1>0){
        ch1 = (*s1 >='a' && *s1 <= 'z')?(*s1-32):*s1;
        ch2 = (*s2 >='a' && *s2 <= 'z')?(*s2-32):*s2;
        if(ch1!=ch2){
            return -1;
        }
        s1++;
        s2++;
        len1--;
    }
    return 0;
}



int main(){
    std::cout<<"enter string"<<std::endl;
    char* str1 = "NAME";
    char* str2 = "name";
    std::cout<<str1<<","<<str2<<";"<<ignore_case_strcmp(str1,str2)<<std::endl;
    std::cout<<str1<<","<<str2<<";";
}