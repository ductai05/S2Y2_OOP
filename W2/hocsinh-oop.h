#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric> 
#include <fstream>
#include <sstream>

using namespace std;

class HocSinh {
private:
    int mshs;
    string tenhs;
    double toan, ly, hoa, van, anh;
    double tb;
    string diachi;
    string ghichu;
    string grade;
public:
    HocSinh();
    HocSinh(int mshs, string tenhs, double toan, double ly, double hoa, double van, double anh, string diachi, string ghichu);
    static bool hople(int mshs, string tenhs, double toan, double ly, double hoa, double van, double anh, string diachi, string ghichu);
    bool chinhsua(int mshs = -1, string tenhs = "", double toan = -1, double ly = -1, double hoa = -1, double van = -1, double anh = -1, string diachi = "", string ghichu = "");
    void tinhtb();
    void info();
    string info(bool isSave);
    int info_mshs();
    double info_tb();
};

class Lop {
private:
    vector<HocSinh*> dsHS;
    unordered_map<int, int> mshs_index;
public:
    Lop();
    ~Lop();
    int timHS(int mshs);
    void themHS();
    void suaHS();
    void xoaHS();
    void xemDS();

    void luuDS();
    void readLine(stringstream& ss, int& mshs, string& tenhs, 
        double& toan, double& ly, double& hoa, double& van, 
        double& anh, string& diachi, string& ghichu);
    void docDS();
    void timHS();

    void tuongtac();
};

void interact();