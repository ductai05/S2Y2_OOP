#include "bignum-oop.h"

bigNum::bigNum() {
    num = "0";
}

bigNum::bigNum(string num) {
    this->num = num;
}

bigNum bigNum::nhap(){
    string str;
    cout << "Nhap so nguyen duong: ";
    cin >> str;
    return bigNum(str);
}

bigNum bigNum::operator+(bigNum other) {
    string a = num, b = other.num;
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
    string res = "";
    int carry = 0;
    for (int i = a.length() - 1; i >= 0; i--) {
        int sum = a[i] - '0' + b[i] - '0' + carry;
        res = to_string(sum % 10) + res;
        carry = sum / 10;
    }
    if (carry) res = "1" + res;
    return bigNum(res);
}

bigNum bigNum::operator-(bigNum other) {
    string a = num, b = other.num;
    string res = "";
    bool neg = false;
    if (bigNum(a).operator<(bigNum(b))) {
        swap(a, b);
        neg = true;
    }
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
    int carry = 0;
    for (int i = a.length() - 1; i >= 0; i--) {
        int sub = a[i] - b[i] - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else carry = 0;
        res = to_string(sub) + res;
    }
    while (res.length() > 1 && res[0] == '0') res = res.substr(1);
    if (neg) res = "-" + res;
    return bigNum(res);
}

bigNum bigNum::operator*(bigNum other) {
    string a = num, b = other.num;
    string res = "";
    for (int i = a.length() - 1; i >= 0; i--) {
        string tmp = "";
        int carry = 0;
        for (int j = b.length() - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0') + carry;
            tmp = to_string(mul % 10) + tmp;
            carry = mul / 10;
        }
        if (carry) tmp = to_string(carry) + tmp;
        for (int k = 0; k < a.length() - 1 - i; k++) tmp += "0";
        res = bigNum(res).operator+(bigNum(tmp)).num;
    }
    return bigNum(res);
}

bigNum bigNum::operator/(bigNum other) {
    string a = num, b = other.num;
    
    if (b == "0") {
        // Handle division by zero
        return bigNum("0"); // Or throw an exception
    }
    
    string res = "";
    string tmp = "";
    
    for (int i = 0; i < a.length(); i++) {
        tmp += a[i];
        
        // Remove leading zeros
        while (tmp.length() > 1 && tmp[0] == '0') {
            tmp = tmp.substr(1);
        }
        
        int cnt = 0;
        while (tmp.length() > b.length() || (tmp.length() == b.length() && tmp.compare(b) >= 0)) {
            bigNum tempNum(tmp);
            bigNum otherNum(b);
            tempNum = tempNum - otherNum;
            tmp = tempNum.num;
            cnt++;
        }
        
        res += to_string(cnt);
    }
    
    // Remove leading zeros from result
    while (res.length() > 1 && res[0] == '0') {
        res = res.substr(1);
    }
    
    return bigNum(res);
}

bool bigNum::operator<(bigNum other) {
    string a = num, b = other.num;
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
    return a.compare(b) < 0;
}

void bigNum::xuat() {
    cout << num << "\n";
}

void interact(){
    bigNum a = bigNum::nhap();
    bigNum b = bigNum::nhap();
    a.operator+(b).xuat();
    a.operator-(b).xuat();
    a.operator*(b).xuat();
    a.operator/(b).xuat();
}

int main(){
    interact();
    return 0;
}