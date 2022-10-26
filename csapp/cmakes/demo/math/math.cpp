//
// Created by LYF on 2022/10/24.
//

#include "math.h"
#include "iostream"
#include "stdio.h"

using namespace std;
int add(int a,int b){
    cout<<"a+b="<<a+b;
    return a+b;
}

int main(){
    std::string file_path_name = "E:\\ClionProjects\\practices\\csapp\\cmakes\\demo\\math\\files\\hello.txt";
    int ret1 = ::remove("test");
    int ret2 = ::remove(file_path_name.c_str());
    cout<<ret1<<";"<<ret2;
    add(1,2);
}