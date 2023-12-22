#include<iostream>
using namespace std;
class ConNguoi{
protected:
    string Ten;
    string Tuoi;
    string GioiTinh;
public:
    ConNguoi(){};
    ~ConNguoi(){};
    virtual void Nhap() = 0;
    virtual void Xuat() = 0;
    virtual bool KhenThuong() = 0;
};
class SinhVien : public  ConNguoi{
private:
    string Lop;
    double DTB;
public:
    SinhVien(){};
    ~SinhVien(){};
    void Nhap(){
        cout << "Nhap Ten: "; cin >> this->Ten;
        cout << "Nhap Tuoi: "; cin >> this->Tuoi;
        cout << "Nhap Gioi Tinh: "; cin >> this->GioiTinh;
        cout << "Nhap Lop cua SV: "; cin >> this->Lop;
        cout << "Nhap Diem Trung Binh: "; cin >> this->DTB;
    }
    void Xuat(){
        cout << this->Ten << "\t" << this->Tuoi <<"\t"<<this->GioiTinh << "\t" << this->Lop << "\t" << this->DTB << endl;
    }
    bool KhenThuong(){
        return DTB >= 8;
    }
};
class GiangVien: public ConNguoi{
private:
    string BoMon;
    int SoBaiBao;
public:
    GiangVien(){};
    ~GiangVien(){};
    void Nhap(){
        cout << "Nhap Ten: "; cin >> this->Ten;
        cout << "Nhap Tuoi: "; cin >> this->Tuoi;
        cout << "Nhap Gioi Tinh: "; cin >> this->GioiTinh;
        cout << "Nhap Bo Mon Giang Day: "; cin >> this->BoMon;
        cout << "Nhap So Bai Bao: "; cin >> this->SoBaiBao;
    }
    void Xuat(){
        cout << this->Ten << "\t" << this->Tuoi <<"\t"<<this->GioiTinh << "\t" << this->BoMon << "\t" << this->SoBaiBao << endl;
    }
    bool  KhenThuong(){
        return SoBaiBao >= 1;
    }
};
int main(){
    int n;
    cout << "Nhap So Sinh Vien: "; cin >> n;
    ConNguoi* conNguoi[n];
    for(int i = 0; i < n; i++){
        conNguoi[i] = new SinhVien();
        conNguoi[i]->Nhap();
    }
    cout << "\nSinh vien:\n";
    for(int i = 0; i < n; i++){
        conNguoi[i]->Xuat();
    }
    cout << "\nDanh sach Sinh Vien duoc khen thuong: \n";
    for(int i = 0; i < n; i++){
        if(conNguoi[i]->KhenThuong()){
            conNguoi[i]->Xuat();
        }
    }
    int m;
    cout << "\nNhap So Giang Vien: "; cin >> m;
    ConNguoi* conNguoi1[m];
    for(int i = 0; i < m; i++){
        conNguoi1[i] = new GiangVien;
        conNguoi1[i]->Nhap();
    }
    for(int i = 0; i < m; i++){
        conNguoi1[i]->Xuat();
    }
    return 0;
}

