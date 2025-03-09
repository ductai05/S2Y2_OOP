#include "phanso-oop.h"

PhanSo PhanSo::inPhanSo(){
    std::cout << PhanSo::tu << " / " << PhanSo::mau << "\n";
    return *this;
}

PhanSo PhanSo::rutgon(){
    int a = tu, b = mau;
    while (a * b != 0){
        if (a > b){
            a %= b;
        } else {
            b %= a;
        }
    }
    int gcd = a + b;
    tu /= gcd;
    mau /= gcd;
    return *this;
}

PhanSo PhanSo::cong(PhanSo x){
    tu = tu * x.mau + x.tu * mau;
    mau = mau * x.mau;
    rutgon();
    std::cout << "(+)ans: "; inPhanSo();
    return *this;
}

PhanSo PhanSo::tru(PhanSo x){
    tu = tu * x.mau - x.tu * mau;
    mau = mau * x.mau;
    rutgon();
    std::cout << "(-)ans: "; inPhanSo();
    return *this;
}

PhanSo PhanSo::nhan(PhanSo x){
    tu = tu * x.tu;
    mau = mau * x.mau;
    rutgon();
    std::cout << "(*)ans: "; inPhanSo();
    return *this;
}

PhanSo PhanSo::chia(PhanSo x){
    tu = tu * x.mau;
    mau = mau * x.tu;
    rutgon();
    std::cout << "(/)ans: "; inPhanSo();
    return *this;
}

void interact(){
    PhanSo a(10, 17);
    PhanSo b(5, 16);
    a.inPhanSo();
    b.inPhanSo();
    b = a.cong(b);
    a.inPhanSo();
    b.inPhanSo();
}

int main(){
    interact();
}

