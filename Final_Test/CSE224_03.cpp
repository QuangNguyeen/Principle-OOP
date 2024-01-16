#include<iostream>
using namespace std;

class Nguoi {
protected:
    char maNguoi, hoTen, maDV;
    int namSinh;
    double heSoLuong;

public:
    Nguoi() {};
    Nguoi(char id, char name, char idDV, int year, double heso) {
        maNguoi = id;
        hoTen = name;
        maDV = idDV;
        namSinh = year;
        heSoLuong = heso;
    }

    virtual void input() {
        cout << "Nhap Ma Nguoi: "; cin >> maNguoi;
        cout << "Nhap Ho Ten: "; cin >> hoTen;
        cout << "Nhap Ma DV: "; cin >> maDV;
        cout << "Nhap Nam Sinh: "; cin >> namSinh;
        cout << "Nhap He So Luong: "; cin >> heSoLuong;
    }

    virtual void output() const {
        cout << "Id: " << maNguoi << "\t" << "idDV: " << maDV << "\t" << "HoTen: " << hoTen << "\t" << "NamSinh: " << namSinh
             << "\t" << "HeSoLuong: " << heSoLuong;
    }

    virtual ~Nguoi() {}
};

class GiangVien : public Nguoi {
private:
    char monGiangDay;
    int soGio, soBaiBao;

public:
    GiangVien() {};
    GiangVien(char id, char name, char idDV, int year, double heso, char monGD, int hour, int news)
            : Nguoi(id, name, idDV, year, heso) {
        monGiangDay = monGD;
        soBaiBao = news;
        soGio = hour;
    }

    double Luong() const {
        return soGio * 200 + 0.25 * 1200;
    }

    void input() override {
        Nguoi::input();
        cout << "Nhap Mon Giang Day: "; cin >> monGiangDay;
        cout << "Nhap So Gio: "; cin >> soGio;
        cout << "Nhap So Bai Bao: "; cin >> soBaiBao;
    }

    void output() const override {
        Nguoi::output();
        cout << "\tMon Giang Day: " << monGiangDay << "\t" << "SoGio: " << soGio << "\t" << "SoBaiBao: " << soBaiBao;
    }
};

class SinhVien : public Nguoi {
private:
    char monHoc;
    int soTC;
    double DiemQT;

public:
    SinhVien() {};
    SinhVien(char id, char name, char idDV, int year, double heso, char subject, int sotc, double diem)
            : Nguoi(id, name, idDV, year, heso) {
        monHoc = subject;
        soTC = sotc;
        DiemQT = diem;
    }

    double getDiem() const {
        return DiemQT;
    }

    void input() override {
        Nguoi::input();
        cout << "Nhap Mon Hoc: "; cin >> monHoc;
        cout << "Nhap So Tin Chi: "; cin >> soTC;
        cout << "Nhap Diem Qua Trinh: "; cin >> DiemQT;
    }

    void output() const override {
        Nguoi::output();
        cout << "\tMonHoc: " << monHoc << "\t" << "SoTC: " << soTC << "\t" << "DiemQT: " << DiemQT;
    }
};

void selectionSort(Nguoi** list, int n) {
    int i, j, max;
    for (i = 0; i < n - 1; i++) {
        max = i;
        for (j = i + 1; j < n; j++) {
            if (dynamic_cast<GiangVien*>(list[i]) && dynamic_cast<GiangVien*>(list[j]) &&
            static_cast<GiangVien *>(list[j])->Luong() > static_cast<GiangVien *>(list[max])->Luong())
                max = j;

        }
        if (i != max) {
            Nguoi* temp = list[i];
            list[i] = list[max];
            list[max] = temp;
        }
    }
}

int main() {
    int n;
    do {
        cout << "Nhap N Nguoi ( 0 < N <= 100 ): "; cin >> n;
    } while (n <= 0 || n > 100);

    Nguoi* DanhSach[n];

    for (int i = 0; i < n; i++) {
        int choice;
        cout << "Nhap Lua Chon: ( 0 la SV, 1 la GV ): "; cin >> choice;
        if (choice == 0) {
            DanhSach[i] = new SinhVien;
            DanhSach[i]->input();
        } else if (choice == 1) {
            DanhSach[i] = new GiangVien;
            DanhSach[i]->input();
        }
    }

    selectionSort(DanhSach, n);

    cout << "\nDanh Sach Giang Vien sau khi sap xep: \n";
    for (int i = 0; i < n; i++) {
        if (dynamic_cast<GiangVien*>(DanhSach[i])) {
            DanhSach[i]->output();
            cout << endl;
        }
    }

    cout << "\nDanh Sach Sinh Vien Cam Thi: \n";
    for (int i = 0; i < n; i++) {
        if (dynamic_cast<SinhVien*>(DanhSach[i])->getDiem() < 4) {
            DanhSach[i]->output();
            cout << endl;
        }
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        delete DanhSach[i];
    }

    return 0;
}
