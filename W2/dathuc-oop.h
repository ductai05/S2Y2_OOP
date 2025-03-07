#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class DaThuc {
private:
    int degree;
    double *coefficients;
public:
    DaThuc();
    DaThuc(int n, double *a);
    void nhapDaThuc();
    void inDaThuc();
    static DaThuc cong(const DaThuc &x, const DaThuc &y);
    static DaThuc tru(const DaThuc &x, const DaThuc &y);
    static DaThuc nhan(const DaThuc &x, const DaThuc &y);
    static double tinhGiaTri(const DaThuc &a, double x);
};

void interact();