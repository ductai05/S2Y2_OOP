#include "tamgiac-oop.h"

TamGiac::TamGiac() {
    a = b = c = 0;
}

TamGiac::TamGiac(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

TamGiac TamGiac::nhap() {
    cout << "Nhap 3 canh cua tam giac: ";
    double a, b, c;
    cin >> a >> b >> c;
    return TamGiac(a, b, c);
}

void TamGiac::xuat() {
    if (!laTamGiac()) {
        cout << "Khong phai tam giac\n";
        return;
    }
    cout << "Toa do 3 dinh cua tam giac: " << a << ", " << b << ", " << c << "\n";
    if (laTamGiacDeu()) cout << "Tam giac deu\n";
    else if (laTamGiacCan()) cout << "Tam giac can\n";
    else if (laTamGiacVuong()) cout << "Tam giac vuong\n";
    else if (laTamGiac()) cout << "Tam giac thuong\n";
    cout << "Chu vi: " << chuVi() << "\n";
    cout << "Dien tich: " << dienTich() << "\n";
}

double TamGiac::chuVi() {
    return a + b + c;
}

double TamGiac::dienTich() {
    double p = chuVi() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

bool TamGiac::laTamGiac() {
    if (a <= 0 || b <= 0 || c <= 0) return false;
    return a + b > c && a + c > b && b + c > a;
}

bool TamGiac::laTamGiacDeu() {
    return laTamGiac() && a == b && b == c;
}

bool TamGiac::laTamGiacCan() {
    return laTamGiac() && (a == b || b == c || a == c);
}

bool TamGiac::laTamGiacVuong() {
    if (!laTamGiac()) return false;
    double aa = a * a, bb = b * b, cc = c * c;
    return aa + bb == cc || aa + cc == bb || bb + cc == aa;
}

void interact(){
    TamGiac tg = TamGiac::nhap();
    tg.xuat();
}

int main(){
    interact();
    return 0;
}