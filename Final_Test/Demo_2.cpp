#include<iostream>
using namespace std;
class VienChuc{
private:
    string MaVC, HoTen, NamSinh;
    double HSL; // He So Luong
public:
    // Constructor
    VienChuc(string id, string name, string year, double HeSo){
        MaVC = id;
        HoTen = name;
        NamSinh = year;
        HSL = HeSo;
    };
    // getter
    double getHSL(){
        return HSL;
    }
    virtual  void input(){
        cout << "Nhap Ma Vien Chuc: "; cin >> MaVC;
        cout << "Nhap Ho Ten: "; cin >> HoTen;
        cout << "Nhap Nam Sinh: "; cin >> NamSinh;
        cout << "Nhap He So Luong: "; cin >> HSL;
    }
    virtual void output(){
        cout << "Id: " << MaVC << "\t" << "Name: " << HoTen << "\t" << "Year: " << NamSinh << "\t" << "HSL: " << HSL;
    }
    virtual double Luong(){
        // chua dinh nghia gi car
    };
};
class CBHanhChinh : public VienChuc{
private:
    string chucDanh;
    double PhuCap;
public:
    // Constructor
    CBHanhChinh(string id, string name, string year, double HeSo, string chucDanh, double PhuCap): VienChuc(id, name, year, HeSo){
        this->chucDanh = chucDanh;
        this->PhuCap = PhuCap;
    };

    void input(){
        VienChuc::input();
        cout << "Nhap Chuc Danh: "; cin >> chucDanh;
        cout << "Nhap Phu Cap: "; cin >> PhuCap;
    }
    void output(){
        VienChuc::output();
        cout << "\tChuc danh: " << chucDanh << "\t" << "Phu Cap: " << PhuCap << "\t" << "Luong: " << Luong();
    }
    double Luong(){
        return getHSL() * 2000000  + PhuCap;
    }
};
class GiaoVien : public VienChuc{
private:
    string MonDay, TrinhDo;
    int ThamNien;
public:
    GiaoVien(string id, string name, string year, double HeSo, string MonDay, string TrinhDo, int ThamNien): VienChuc(id, name, year, HeSo){
        this->MonDay = MonDay;
        this->TrinhDo = TrinhDo;
        this->ThamNien = ThamNien;
    }
    void input(){
        VienChuc::input();
        cout << "Nhap Mon Day: "; cin >> MonDay;
        cout << "Nhap Trinh Do: "; cin >> TrinhDo;
        cout << "Nhap Tham Nien: "; cin >> ThamNien;
    }
    void output(){
        VienChuc::output();
        cout << "\t" << "Mon Day: " << MonDay << "\t" << "TrinhDo: " << TrinhDo << "\t" << "Tham Nien: " << ThamNien
        << "\t" << "Luong: " << Luong();
    }
    double Luong(){
        return (getHSL() * 2000000 * (130 + ThamNien)) / 100;
    }
};
int main(){
    int n;
    cout << "Nhap So Vien Chuc: "; cin >> n;
    // Tao mang cac con tro kieu Vien Chuc
    VienChuc *DanhSacVC[n];
    for(int i = 0; i < n; i++){
        int choice;
        cout << "Chon Kieu Vien Chuc: ( 0 la HanhChinh, 1 la GiaoVien ): "; cin >> choice;
        if(choice == 0){
            DanhSacVC[i] = new CBHanhChinh("0","0", "0", 0, "0", 0);
            DanhSacVC[i]->input();
        } else if (choice == 1){
            DanhSacVC[i] = new GiaoVien("0", "0", "0", 0, "0", "0", 0);
            DanhSacVC[i]->input();
        }
    }
    for(int i = 0; i < n; i++){
        DanhSacVC[i]->output();
        cout << endl;
    }
    // Tim Vien Chuc Luong Cao Nhat
    double maxLuong = 0;
    int indexMax = 0;
    for(int i = 0; i < n; i++){
        if(DanhSacVC[i]->Luong() > maxLuong){
            maxLuong = DanhSacVC[i]->Luong();
            indexMax = i;
        }
    }
    DanhSacVC[indexMax]->output();
    return 0;
}
