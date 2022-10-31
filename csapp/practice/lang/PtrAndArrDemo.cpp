//
// Created by LYF on 2022/10/29.
//

#include <cstring>
#include <iostream>
#include "PtrAndArrDemo.h"

void PtrAndArrDemo::chars_str()
{
    char* dest = "i am dest";
    std::cout<<dest;
    const char* source = "i am source";
    memcpy(dest,source, strlen(source));
    std::cout<<dest<<std::endl;
    std::cout<<":"<<source;
}

int main(){
    PtrAndArrDemo ptrAndArrDemo = *new PtrAndArrDemo();
    ptrAndArrDemo.chars_str();
}