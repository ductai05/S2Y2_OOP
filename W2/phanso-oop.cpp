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

PhanSo PhanSo::operator+(const PhanSo &x) {
    PhanSo ans(0, 1);
    ans.tu = tu * x.mau + x.tu * mau;
	ans.mau = mau * x.mau;
    ans.rutgon();
	return ans;
}

PhanSo &PhanSo::operator++(){ // tiento; tham chieu den doi tuong sau khi +
    tu += mau;
    return *this;
}

PhanSo PhanSo::operator++(int){ // hauto; ban sao den doi tuong truoc khi +
    PhanSo ans = *this;
    tu += mau;
    return ans;
}

// PhanSo::operator double(){
//     return tu / mau;
// }

PhanSo::operator double(){
    return tu / mau;
} 

void interact(){
    PhanSo a(27, 17);
    PhanSo b(5, 16);
    a.inPhanSo();
    cout << (long long) (a);
}

void interact2(){
    PhanSo a(10, 17);
    PhanSo b(5, 16);
    a.inPhanSo();
    ++(a.inPhanSo());
}

int main(){
    interact(); cout << "\n";
    interact2();
}

