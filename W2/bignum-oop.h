#ifndef BIGNUM_OOP_H
#define BIGNUM_OOP_H

#include <iostream>
#include <cmath>

using namespace std;

class bigNum {
private:
    string num;
public:
    bigNum();
    bigNum(string num);
    bigNum operator+(bigNum other);
    bigNum operator-(bigNum other);
    bigNum operator*(bigNum other);
    bigNum operator/(bigNum other);
    bool operator<(bigNum other);
    void xuat();
    static bigNum nhap();
};

void interact();

#endif