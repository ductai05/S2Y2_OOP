#ifndef TAMGIAC_OOP_H
#define TAMGIAC_OOP_H

#include <iostream>
#include <cmath>

using namespace std;

class TamGiac {
    private:
        double a, b, c;
    public:
        TamGiac();
        TamGiac(double a, double b, double c);
        double chuVi();
        double dienTich();
        bool laTamGiac();
        bool laTamGiacDeu();
        bool laTamGiacCan();
        bool laTamGiacVuong();

        static TamGiac nhap();
        void xuat();
};

void interact();

#endif