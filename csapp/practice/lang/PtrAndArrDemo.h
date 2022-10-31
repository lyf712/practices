//
// Created by LYF on 2022/10/29.
//

#ifndef PRACTICE_PTRANDARRDEMO_H
#define PRACTICE_PTRANDARRDEMO_H


class PtrAndArrDemo {
public:
    PtrAndArrDemo(){}
    ~PtrAndArrDemo(){}
    void chars_str();
    void* data()const{return data_;}
private:
    int flag_;
    void* data_;
};


#endif //PRACTICE_PTRANDARRDEMO_H
