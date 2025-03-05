#include <iostream>

using namespace std;

class Student {
private:
    string name;
    int age;
    int student_id;

public:
    Student(string n, int a, int id) : name(n), age(a), student_id(id) {}
    void getInfo();
};

class PhanSo {
private:
    double tu;
    double mau;
public:
    PhanSo(double a, double b) : tu(a), mau(b) {}
    void inPhanSo();
    void rutgon();
    void cong(PhanSo x);
    void tru(PhanSo x);
    void nhan(PhanSo x);
    void chia(PhanSo x);
};

void interact();