#ifndef MYINTARR_H
#define MYINTARR_H

#include <iostream>

using namespace std;

class MyIntArray {
private:
    int* pArr;
    int size;
public:
    ~MyIntArray();
    MyIntArray(int sz);
    MyIntArray& operator = (const MyIntArray&);
    MyIntArray copy(const int *array, int sz);
    void printArray();
};

#endif