#include "myIntArr.h"

MyIntArray::~MyIntArray() {
    if (size > 0) {
        size = 0;
        delete[] pArr; pArr = nullptr;
    } 
}

MyIntArray:: MyIntArray(int sz){
    if (sz <= 0) {
        size = 0;
        pArr = nullptr;
        return;
    } 
    size = sz;
    pArr = new int [size];
    for (int i = 0; i < size; i++) {
        pArr[i] = 0;
    }
}

MyIntArray& MyIntArray::operator=(const MyIntArray& src){
    if (this != &src) {
        delete [] pArr;
        size = src.size;
        pArr = new int [size];
        for (int i = 0; i < size; ++i){
            pArr[i] = src.pArr[i];
        }
    }
    return *this;
}

MyIntArray MyIntArray::copy(const int *array, int sz){
    delete [] pArr;
    size = sz;
    pArr = new int [sz];
    for (int i = 0; i < sz; ++i){
        pArr[i] = array[i];
    }
    return *this;
}

void MyIntArray::printArray(){
    for (int i = 0; i < size; i++) {
        cout << pArr[i] << " ";
    }
    cout << endl;
}

void interact(){
    int* arr = new int [5];
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }
    MyIntArray myarr(5);
    myarr = myarr.copy(arr, 5);
    myarr.printArray();
}

int main() {
    interact();
    return 0;
}