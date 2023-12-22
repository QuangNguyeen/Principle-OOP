#include<iostream>
#include <vector>
using namespace std;

class MonHoc {
private:
    string TenMonHoc;
    double DiemTP;
    double DiemThi;
    int soTC;

public:
    MonHoc() {};
    ~MonHoc() {};
    void input() {
        cout << "Nhap TenMH: "; cin >> this->TenMonHoc;
        cout << "Nhap DiemTP: "; cin >> this->DiemTP;
        cout << "Nhap DiemThi: "; cin >> this->DiemThi;
        cout << "Nhap soTC: "; cin >> this->soTC;
    };
    void output() {
        cout << this->TenMonHoc << "\t" << this->DiemThi << "\t" << this->DiemTP << "\t" << this->soTC << "\n";
    };
    double getDiemTB() {
        return DiemTP * 0.3 + DiemThi * 0.7;
    }
    int getSoTC() {
        return soTC;
    }
};

class SinhVien {
private:
    string MaSV;
    string TenSV;
    int soMH;
    vector<MonHoc> DanhSachMH;

public:
    SinhVien() {};
    ~SinhVien() {};
    friend void DTK(SinhVien sv);
    friend istream& operator>>(istream& in, SinhVien& sv);
    friend ostream& operator<<(ostream& out, SinhVien sv);
};

void DTK(SinhVien sv) {
    double tongTC = 0;
    double sum = 0;
    for (int i = 0; i < sv.soMH; i++) {
        sum += sv.DanhSachMH[i].getDiemTB() * sv.DanhSachMH[i].getSoTC();
        tongTC += sv.DanhSachMH[i].getSoTC();
    }
    cout << "Diem trung binh cua sinh vien: " << (sum / tongTC) << endl;
}

istream& operator>>(istream& in, SinhVien& sv) {
    cout << "Nhap Ten SV: "; in >> sv.TenSV;
    cout << "Nhap MaSV: "; in >> sv.MaSV;
    cout << "Nhap soMH:"; in >> sv.soMH;
    for (int i = 0; i < sv.soMH; i++) {
        MonHoc temp;
        temp.input();
        sv.DanhSachMH.push_back(temp);
    }
    return in;
}

ostream& operator<<(ostream& out, SinhVien sv) {
    out << sv.TenSV << "\t" << sv.MaSV << "\t" << sv.soMH << "\n";
    cout << "Danh sach cac mon hoc cua sinh vien: \n";
    for (int i = 0; i < sv.soMH; i++) {
        sv.DanhSachMH[i].output();
    }
    return out;
}

int main() {
    SinhVien sv;
    cin >> sv;
    cout << sv;
    DTK(sv);
    return 0;
}
