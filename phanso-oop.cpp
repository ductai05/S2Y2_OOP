#include "phanso-oop.h"
void Student::getInfo(){
    std::cout << "Name: " << Student::name << "\n";
    std::cout << "Age: " << Student::age << "\n";
    std::cout << "Student ID: " << Student::student_id << "\n";
};

// PHANSO
void PhanSo::inPhanSo(){
    std::cout << PhanSo::tu << " / " << PhanSo::mau << "\n";
}

void PhanSo::rutgon(){
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
}

void PhanSo::cong(PhanSo x){
    tu = tu * x.mau + x.tu * mau;
    mau = mau * x.mau;
    rutgon();
    std::cout << "(+)ans: "; inPhanSo();
}

void PhanSo::tru(PhanSo x){
    tu = tu * x.mau - x.tu * mau;
    mau = mau * x.mau;
    rutgon();
    std::cout << "(-)ans: "; inPhanSo();
}

void PhanSo::nhan(PhanSo x){
    tu = tu * x.tu;
    mau = mau * x.mau;
    rutgon();
    std::cout << "(*)ans: "; inPhanSo();
}

void PhanSo::chia(PhanSo x){
    tu = tu * x.mau;
    mau = mau * x.tu;
    rutgon();
    std::cout << "(/)ans: "; inPhanSo();
}

void interact(){
    PhanSo a(10, 17);
    PhanSo b(5, 16);
    a.inPhanSo();
    b.inPhanSo();
    a.cong(b);
    a.chia(b);
    a.nhan(a);
}

int main(){
    interact();
}

