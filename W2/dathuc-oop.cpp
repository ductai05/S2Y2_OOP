#include "dathuc-oop.h"

DaThuc::DaThuc(){
    degree = -1;
    coefficients = NULL;
}

DaThuc::DaThuc(int n, double *a){
    degree = n;
    coefficients = new double[n + 1];
    for (int i = 0; i <= n; i++){
        coefficients[i] = a[i];
    }
}

DaThuc::~DaThuc(){
    if (coefficients != NULL){
        delete[] coefficients;
    }
}

void DaThuc::nhapDaThuc(){
    std::cout << "Nhap bac cua da thuc: ";
    std::cin >> degree;
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; i++){
        std::cout << "Nhap he so cua x^" << i << ": ";
        std::cin >> coefficients[i];
    }
}

void DaThuc::inDaThuc(){
    if (degree == -1){
        std::cout << "Da thuc rong\n";
        return;
    }
    auto doubleToString = [](double value) -> std::string {
        std::ostringstream oss;
        oss << value;
        return oss.str();
    };

    std::string result = "";
    for (int i = 0; i <= degree; i++){
        if (coefficients[i] != 0){
            if (coefficients[i] > 0 && i > 0) result += ((result == "") ? "" : " + ");
            if (coefficients[i] < 0) result += ((result == "") ? "-" : " - ");

            if (coefficients[i] != 1 && coefficients[i] != -1) 
                result += doubleToString(abs(coefficients[i]));

            if (coefficients[i] != 1 && coefficients[i] != -1 && i > 0) result += " * ";

            if (coefficients[i] != 0 && i >= 1) result += "x";

            if (i > 1){
                result += "^" + std::to_string(i);
            }
        }
    }
    if (result == ""){
        result = "0";
    }
    for (int i = 0; i <= degree; i++){
        cout << coefficients[i] << " ";
    } cout << "\n";
    std::cout << result << "\n";
}

DaThuc DaThuc::cong(const DaThuc &x, const DaThuc &y){
    int n = (x.degree > y.degree) ? x.degree : y.degree;
    double *a = new double[n + 1];
    for (int i = 0; i <= n; i++){
        a[i] = ((i <= x.degree) ? x.coefficients[i] : 0) + ((i <= y.degree) ? y.coefficients[i] : 0);
    }
    return DaThuc(n, a);
}

DaThuc DaThuc::tru(const DaThuc &x, const DaThuc &y){
    int n = (x.degree > y.degree) ? x.degree : y.degree;
    double *a = new double[n + 1];
    for (int i = 0; i <= n; i++){
        a[i] = ((i <= x.degree) ? x.coefficients[i] : 0) - ((i <= y.degree) ? y.coefficients[i] : 0);
    }
    return DaThuc(n, a);
}

DaThuc DaThuc::nhan(const DaThuc &x, const DaThuc &y){
    int n = x.degree + y.degree;
    double *a = new double[n + 1];
    for (int i = 0; i <= n; i++){
        a[i] = 0;
    }
    for (int i = 0; i <= x.degree; i++){
        for (int j = 0; j <= y.degree; j++){
            a[i + j] += x.coefficients[i] * y.coefficients[j];
        }
    }
    return DaThuc(n, a);
}

double DaThuc::tinhGiaTri(const DaThuc &a, double x){
    double result = 0;
    for (int i = 0; i <= a.degree; i++){
        result += a.coefficients[i] * pow(x, i);
    }
    return result;
}

void interact(){
    DaThuc A;
    A.nhapDaThuc();
    A.inDaThuc();

    DaThuc B;
    B.nhapDaThuc();
    B.inDaThuc();

    DaThuc C = DaThuc::cong(A, B);
    DaThuc D = DaThuc::tru(A, B);
    DaThuc E = DaThuc::nhan(A, B);
    cout << "\n";
    cout << "Tong hai da thuc: "; C.inDaThuc();
    cout << "Hieu hai da thuc: "; D.inDaThuc();
    cout << "Tich hai da thuc: "; E.inDaThuc();

    double x;
    cout << "Nhap x: ";
    cin >> x;
    cout << "Gia tri cua da thuc A tai x = " << x << " la: " << DaThuc::tinhGiaTri(A, x) << "\n";
    cout << "Gia tri cua da thuc B tai x = " << x << " la: " << DaThuc::tinhGiaTri(B, x) << "\n";

    A.~DaThuc();
    B.~DaThuc();
    C.~DaThuc();
    D.~DaThuc();
    E.~DaThuc();
}

int main(){
    interact();
    return 0;
}
