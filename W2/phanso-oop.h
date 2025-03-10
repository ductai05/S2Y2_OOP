#ifndef PHANSO_OOP_H
#define PHANSO_OOP_H

#include <iostream>

using namespace std;

class PhanSo {
private:
    double tu;
    double mau;
public:
    PhanSo(double a, double b) : tu(a), mau(b) {}
    PhanSo inPhanSo();
    PhanSo rutgon();
    PhanSo cong(PhanSo x);
    PhanSo tru(PhanSo x);
    PhanSo nhan(PhanSo x);
    PhanSo chia(PhanSo x);
};

void interact();

#endif