#include "hocsinh-oop.h"

HocSinh::HocSinh() {
    mshs = 0;
    tenhs = "";
    toan = 0;
    ly = 0;
    hoa = 0;
    van = 0;
    anh = 0;
    diachi = "";
    ghichu = "";
    tb = 0;
}

HocSinh::HocSinh(int mshs, string tenhs, double toan, double ly, 
    double hoa, double van, double anh, string diachi, string ghichu){
    this->mshs = mshs;
    this->tenhs = tenhs;
    this->toan = toan;
    this->ly = ly;
    this->hoa = hoa;
    this->van = van;
    this->anh = anh;
    this->diachi = diachi;
    this->ghichu = ghichu;
    this->tinhtb();
}

bool HocSinh::hople(int mshs, string tenhs, double toan, 
    double ly, double hoa, double van, double anh, 
    string diachi, string ghichu){
    if (mshs <= 0 && mshs != -1)
        return false;

    for (char c : tenhs) {
        if (!isalpha(c) && !isspace(c))
            return false;
    }
    
    if ((toan < 0 || toan > 10) && toan != -1)
       return false;
    if ((ly < 0 || ly > 10) && ly != -1)
       return false;
    if ((hoa < 0 || hoa > 10) && hoa != -1)
       return false;
    if ((van < 0 || van > 10) && van != -1)
       return false;
    if ((anh < 0 || anh > 10) && anh != -1)
       return false;

    return true;
}

bool HocSinh::chinhsua(int mshs, string tenhs, double toan, 
    double ly, double hoa, double van, double anh, 
    string diachi, string ghichu){
    if (!hople(mshs, tenhs, toan, ly, hoa, van, anh, diachi, ghichu)){
        return false;
    }
    
    if (mshs != -1) this->mshs = mshs;
    if (tenhs != "") this->tenhs = tenhs;
    if (toan != -1) this->toan = toan;
    if (ly != -1) this->ly = ly;
    if (hoa != -1) this->hoa = hoa;
    if (van != -1) this->van = van;
    if (anh != -1) this->anh = anh;
    if (diachi != "") this->diachi = diachi;
    if (ghichu != "") this->ghichu = ghichu;

    this->tinhtb();

    return true;
}

void HocSinh::tinhtb(){
    tb = (toan + ly + hoa + van + anh) / 5;
    grade = "";
    if (tb >= 9){
        grade = "Xuat sac";
    } else if (tb >= 8){
        grade = "Gioi";
    } else if (tb >= 6.5){
        grade = "Kha";
    } else if (tb >= 5){
        grade = "Trung binh";
    } else {
        grade = "Yeu";
    }
}

void HocSinh::info(){
    cout << "MSHS: " << mshs << ", ";
    cout << "Ten: " << tenhs << ", ";
    cout << "Toan: " << toan << ", ";
    cout << "Ly: " << ly << ", ";
    cout << "Hoa: " << hoa << ", ";
    cout << "Van: " << van << ", ";
    cout << "Anh: " << anh << ", ";
    cout << "Diem TB: " << tb << ", ";
    cout << "Xep loai: " << grade << ", ";
    cout << "Dia chi: " << diachi << ", ";
    cout << "Ghi chu: " << ghichu << "\n";
}

string HocSinh::info(bool isSave){
    string result = "";
    result += "MSHS: " + to_string(mshs) + ", ";
    result += "Ten: " + tenhs + ", ";
    result += "Toan: " + to_string(toan) + ", ";
    result += "Ly: " + to_string(ly) + ", ";
    result += "Hoa: " + to_string(hoa) + ", ";
    result += "Van: " + to_string(van) + ", ";
    result += "Anh: " + to_string(anh) + ", ";
    result += "Diem TB: " + to_string(tb) + ", ";
    result += "Xep loai: " + grade + ", ";
    result += "Dia chi: " + diachi + ", ";
    result += "Ghi chu: " + ghichu;
    return result;
}

int HocSinh::info_mshs(){
    return mshs;
}

double HocSinh::info_tb(){
    return tb;
}

Lop::Lop(){
    dsHS = vector<HocSinh*>();
}

Lop::~Lop(){
    for (HocSinh* hs : dsHS){
        delete hs;
    }
    mshs_index.clear();
    dsHS.clear();
}

int Lop::timHS(int mshs){
    for (int i = 0; i < dsHS.size(); i++){
        if (dsHS[i]->info_mshs() == mshs){
            return i;
        }
    }
    return -1;
}

void Lop::themHS(){
    int mshs;
    string tenhs;
    double toan, ly, hoa, van, anh;
    string diachi;
    string ghichu;
    cout << "Nhap ma so hoc sinh: "; cin >> mshs;
    cout << "Nhap ten hoc sinh: "; cin >> tenhs;

    cout << "Nhap diem toan: "; cin >> toan;
    cout << "Nhap diem ly: "; cin >> ly;
    cout << "Nhap diem hoa: "; cin >> hoa;
    cout << "Nhap diem van: "; cin >> van;
    cout << "Nhap diem anh: "; cin >> anh;
    
    cout << "Nhap dia chi: "; cin >> diachi;
    cout << "Nhap ghi chu: "; cin >> ghichu;
    
    HocSinh* hs = new HocSinh(mshs, tenhs, toan, ly, hoa, van, anh, diachi, ghichu);
    hs->tinhtb();
    dsHS.push_back(hs);
}

void Lop::suaHS(){
    int mshs;
    cout << "Nhap ma so hoc sinh can sua: "; cin >> mshs;
    int id = timHS(mshs);
    if (id == -1){
        cout << "Khong tim thay hoc sinh" << "\n";
        return;
    }
    int choice = 0;
    bool isDone = false;
    while (true){
        cout << "1. Sua ma so hoc sinh" << "\n";
        cout << "2. Sua ten" << "\n";
        cout << "3. Sua diem toan" << "\n";
        cout << "4. Sua diem ly" << "\n";
        cout << "5. Sua diem hoa" << "\n";
        cout << "6. Sua diem van" << "\n";
        cout << "7. Sua diem anh" << "\n";
        cout << "8. Sua dia chi" << "\n";
        cout << "9. Sua ghi chu" << "\n";
        cout << "0. Thoat" << "\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice){
            case 1: {
                int mshs;
                cout << "Nhap ma so hoc sinh: "; cin >> mshs;
                isDone = dsHS[id]->chinhsua(mshs); break;
            }
            case 2: {
                string tenhs;
                cout << "Nhap ten hoc sinh: "; cin >> tenhs;
                isDone = dsHS[id]->chinhsua(-1, tenhs); break;
            }
            case 3: {
                double toan;
                cout << "Nhap diem toan: "; cin >> toan;
                isDone = dsHS[id]->chinhsua(-1, "", toan); break;
            }
            case 4: {
                double ly;
                cout << "Nhap diem ly: "; cin >> ly;
                isDone = dsHS[id]->chinhsua(-1, "", -1, ly); break;
            }
            case 5: {
                double hoa;
                cout << "Nhap diem hoa: "; cin >> hoa;
                isDone = dsHS[id]->chinhsua(-1, "", -1, -1, hoa); break;
            }
            case 6: {
                double van;
                cout << "Nhap diem van: "; cin >> van;
                isDone = dsHS[id]->chinhsua(-1, "", -1, -1, -1, van); break;
            }
            case 7: {
                double anh;
                cout << "Nhap diem anh: "; cin >> anh;
                isDone = dsHS[id]->chinhsua(-1, "", -1, -1, -1, -1, anh); break;
            }
            case 8: {
                string diachi;
                cout << "Nhap dia chi: "; cin >> diachi;
                isDone = dsHS[id]->chinhsua(-1, "", -1, -1, -1, -1, -1, diachi); break;
            }
            case 9: {
                string ghichu;
                cout << "Nhap ghi chu: "; cin >> ghichu;
                isDone = dsHS[id]->chinhsua(-1, "", -1, -1, -1, -1, -1, "", ghichu); break;
            }
            case 0:
                return;
            default:
                cout << "Lua chon khong hop le" << "\n"; break;
        }
        if (isDone){
            cout << "Da sua hoc sinh" << "\n";
        } else {
            cout << "Sua hoc sinh that bai" << "\n";
        }
    }
}

void Lop::xoaHS(){
    int mshs;
    cout << "Nhap ma so hoc sinh can xoa: "; cin >> mshs;
    int id = timHS(mshs);
    if (id == -1){
        cout << "Khong tim thay hoc sinh" << "\n";
        return;
    }
    cout << "Co chac chan xoa hoc sinh nay khong? (y/n): ";
    string choice;
    cin >> choice;
    if (choice == "y"){
        dsHS.erase(dsHS.begin() + id);
        cout << "Da xoa hoc sinh" << "\n";
    } else {
        cout << "Huy xoa hoc sinh" << "\n";
    }
}

void Lop::xemDS(){
    vector<int> listID(dsHS.size());
    iota(listID.begin(), listID.end(), 0);

    while (true) {
        cout << "1. Danh sach HS: MSHS tang dan\n";
        cout << "2. Danh sach HS: MSHS giam dan\n";
        cout << "3. Danh sach HS: Diem TB tang dan\n";
        cout << "4. Danh sach HS: Diem TB giam dan\n";
        cout << "5. Thoat\n";
        cout << "Nhap lua chon: ";
        int choice = 0;
        cin >> choice;
        
        switch (choice){
            case 1:
                sort(listID.begin(), listID.end(), [&](int a, int b){
                    return dsHS[a]->info_mshs() < dsHS[b]->info_mshs();
                }); break;
            case 2:
                sort(listID.begin(), listID.end(), [&](int a, int b){
                    return dsHS[a]->info_mshs() > dsHS[b]->info_mshs();
                }); break;
            case 3:
                sort(listID.begin(), listID.end(), [&](int a, int b){
                    return dsHS[a]->info_tb() < dsHS[b]->info_tb();
                }); break;
            case 4:
                sort(listID.begin(), listID.end(), [&](int a, int b){
                    return dsHS[a]->info_tb() > dsHS[b]->info_tb();
                }); break;
            case 5:
                return;
            default:
                cout << "Lua chon khong hop le" << "\n"; break;
        }
        
        for (int i : listID){
            dsHS[i]->info();
        }
    }
}

void Lop::luuDS(){
    string filename;
    cout << "Nhap ten file de luu: "; cin >> filename;
    ofstream file(filename);
    for (HocSinh* hs : dsHS){
        file << hs->info(true) << "\n";
    }
    file.close();
    cout << "Da luu danh sach hoc sinh" << "\n";
}

void Lop::readLine(stringstream& ss, int& mshs, string& tenhs, 
    double& toan, double& ly, double& hoa, double& van, 
    double& anh, string& diachi, string& ghichu){
    string temp;
    
    getline(ss, temp, ',');
    mshs = stoi(temp.substr(temp.find(": ") + 2));
    
    getline(ss, temp, ',');
    tenhs = temp.substr(temp.find(": ") + 2);
    
    getline(ss, temp, ',');
    toan = stod(temp.substr(temp.find(": ") + 2));
    
    getline(ss, temp, ',');
    ly = stod(temp.substr(temp.find(": ") + 2));
    
    getline(ss, temp, ',');
    hoa = stod(temp.substr(temp.find(": ") + 2));
    
    getline(ss, temp, ',');
    van = stod(temp.substr(temp.find(": ") + 2));
    
    getline(ss, temp, ',');
    anh = stod(temp.substr(temp.find(": ") + 2));

    getline(ss, temp, ',');
    // double tb = stod(temp.substr(temp.find(": ") + 2));

    getline(ss, temp, ',');
    // string grade = temp.substr(temp.find(": ") + 2);
    
    getline(ss, temp, ',');
    diachi = temp.substr(temp.find(": ") + 2);
    
    getline(ss, temp, ',');
    ghichu = temp.substr(temp.find(": ") + 2);
}

void Lop::docDS(){
    string filename;
    cout << "Nhap ten file de doc: "; cin >> filename;
    ifstream file(filename);
    string line;
    while (getline(file, line)){
        stringstream ss(line);
        int mshs;
        string tenhs;
        double toan, ly, hoa, van, anh;
        string diachi;
        string ghichu;
        readLine(ss, mshs, tenhs, toan, ly, hoa, van, anh, diachi, ghichu);
        if (!HocSinh::hople(mshs, tenhs, toan, ly, hoa, van, anh, diachi, ghichu)){
            continue;
        }
        HocSinh* hs = new HocSinh(mshs, tenhs, toan, ly, hoa, van, anh, diachi, ghichu);
        hs->tinhtb();
        dsHS.push_back(hs);
    }
    file.close();
    cout << "Da doc danh sach hoc sinh" << "\n";
}

void Lop::timHS(){
    int mshs;
    cout << "Nhap ma so hoc sinh can tim: "; cin >> mshs;
    int id = timHS(mshs);
    if (id == -1){
        cout << "Khong tim thay hoc sinh" << "\n";
        return;
    }
    dsHS[id]->info();
}

void Lop::tuongtac(){
    int mshs;
    string tenhs;
    double toan, ly, hoa, van, anh;
    string diachi;
    string ghichu;
    int choice = 0;
    while (true){
        cout << "\n";
        cout << "1. Them hoc sinh" << "\n";
        cout << "2. Cap nhat thong tin hoc sinh" << "\n";
        cout << "3. Xoa hoc sinh" << "\n";
        cout << "4. Xem danh sach hoc sinh" << "\n";
        cout << "5. Luu danh sach hoc sinh" << "\n";
        cout << "6. Doc danh sach hoc sinh" << "\n";
        cout << "7. Tim kiem hoc sinh" << "\n";
        cout << "0. Thoat" << "\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice){
            case 1:
                themHS(); break;
            case 2:
                suaHS(); break;
            case 3:
                xoaHS(); break;
            case 4:
                xemDS(); break;
            case 5:
                luuDS(); break;
            case 6:
                docDS(); break;
            case 7:
                timHS(); break;
            case 0:
                return;
            default:
                cout << "Lua chon khong hop le" << "\n"; break;
        }
    }
}

void interact(){
    Lop lop = Lop();
    lop.tuongtac();
    cout << "Hoan thanh Quan li hoc sinh.\n";
    lop.~Lop();
}

int main(){
    interact();
    return 0;
}