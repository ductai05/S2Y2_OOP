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
    PhanSo inPhanSo();
    PhanSo rutgon();
    PhanSo cong(PhanSo x);
    PhanSo tru(PhanSo x);
    PhanSo nhan(PhanSo x);
    PhanSo chia(PhanSo x);
};

void interact();