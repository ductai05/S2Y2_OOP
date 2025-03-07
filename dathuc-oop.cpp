#include "dathuc-oop.h"

DaThuc::DaThuc(int n, double *a){
    degree = n;
    coefficients = new double[n];
    for (int i = 0; i < n; i++){
        coefficients[i] = a[i];
    }
}

void DaThuc::inDaThuc(){
    // for (int i = 0; i < degree; i++){
    //     cout << coefficients[i] << " "; 
    // } cout << "\n";
    cout << ((coefficients[0] == 0) ? "" : to_string(coefficients[0]) + " + ");
    cout << ((coefficients[1] == 0) ? "" : to_string(coefficients[1]) + "x + ");
    for (int i = 2; i < degree; i++){
        cout << coefficients[i] << "x^" << i << " + ";
    }
    // cout << coefficients[degree] << "x^" << degree << "\n";
}

void interact(){
    DaThuc A(3, new double[3]{1, 2, 3});
    A.inDaThuc();
}

int main(){
    interact();
}
