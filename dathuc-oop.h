#include <iostream>
#include <string>

using namespace std;

class DaThuc {
private:
    int degree;
    double *coefficients;
public:
    DaThuc(int n, double *a);
    void inDaThuc();
    // DaThuc cong(DaThuc x);
    // void tru(DaThuc x);
    // void nhan(DaThuc x);
    // void chia(DaThuc x);
    // void daoHam();
    // void nguyenHam();
};

void interact();