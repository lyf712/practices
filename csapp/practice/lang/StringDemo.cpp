//
// Created by LYF on 2022/10/29.
//

#include <cstring>
#include <regex>
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

int regex_match(){
    // patern -- % 匹配任意字符串 ，_ 匹配单个任意字符

    // .* 匹配任意字符？？--%
    // .
    // 将parttern进行改造， 遇到%替换为.*,遇到_替换为.
    std::string str="";
    //str.replace("%",".*",str.length());
    //str.replace
    char* old_pattern = "%m_";
    std::string new_patter="";
    for(int i=0;i< strlen(old_pattern);i++){
        //new_patter.append(old_pattern[i]);
        if(old_pattern[i]=='%'){
            new_patter.insert(new_patter.end(),'.');
            new_patter.insert(new_patter.end(),'*');
            continue;
        }
        if(old_pattern[i]=='_')
        {
            new_patter.insert(new_patter.end(),'.');
            continue;
        }
        new_patter.insert(new_patter.end(),old_pattern[i]);
    }
    std::cout<<new_patter<<std::endl;


    //++++++++++++++++++++++++++++++


    std::regex pattern(new_patter);//[a-z | A-Z] "w.*m."
    std::string s ="ok";
    char* s1 = "wme";
    std::smatch result;
    bool is_match= std::regex_match(s,result,pattern);
    if(is_match){
        std::cout<<"yes"<<std::endl;
    }else{
        std::cout<<"no"<<std::endl;
    }
    std::string tmp_s1 = s1;
    is_match= std::regex_match(tmp_s1,result,pattern);
    if(is_match){
        std::cout<<"yes"<<std::endl;
    }else{
        std::cout<<"no"<<std::endl;
    }
}

int main(){
//    std::cout<<"enter string"<<std::endl;
//    char* str1 = "NAME";
//    char* str2 = "name";
//    std::cout<<str1<<","<<str2<<";"<<ignore_case_strcmp(str1,str2)<<std::endl;
//    std::cout<<str1<<","<<str2<<";";
    regex_match();

}