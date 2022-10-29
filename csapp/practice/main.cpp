//
// Created by LYF on 2022/10/29.
//
#include <cstdlib>
#include <strsafe.h>
#include "stdio.h"
#include "iostream"
#include "typecast/TypeCastDemo.h"

const int MAX_NUM=20;

typedef struct _Value{
    int flag;
    void *data;
}Value;

typedef struct {
    char *relation_name;    // Relation to insert into
    size_t value_num;       // Length of values
    Value values[MAX_NUM];  // values to insert
} Inserts;

int main(){
    Value values_1[10];
    values_1[0].flag=1;
    values_1[0].data= (void *) "ok1";
    values_1[1].flag=2;
    values_1[1].data= (void *) "ok2";
    Value* values_2 = values_1;

    //values_2 = values_1;
    std::cout<<values_2->flag<<(char *)values_2->data<<std::endl;
    values_2++;
    std::cout<<values_2->flag<<(char *)values_2->data<<std::endl;
}