#include<iostream>
using namespace std;
class Nguoi{
private:
    char maNguoi, maDV;
    char hoTen;
    int namSinh;
    double heSoLuong;
public:
    Nguoi(){};
    Nguoi(char id, char DV, char name, int year, double hs){
        maNguoi = id;
        maDV = DV;
        hoTen = name;
        namSinh = year;
        heSoLuong = hs;
    }
    virtual void input(){
        cout << "Nhap Ma Nguoi: "; cin >> maNguoi;
        cout << "Nhap Ho Ten: "; cin >> hoTen;
        cout << "Nhap Ma Don Vi: "; cin >> maDV;
        cout << "Nhap Nam Sinh: "; cin >> namSinh;
        cout << "Nhap He So Luong: "; cin >> heSoLuong;
    }
    virtual void output(){
        cout << "ID: " << maNguoi << "\t" << "ID Don Vi: " << maDV << endl;
        cout << "HoTen: " << hoTen << "\t" << "NamSinh: " << namSinh << "\t" << "HSLuong: " << heSoLuong;
    }
};
class GiangVien : public Nguoi{
private:
    char monGiangDay;
    int soGio;
    int soBaiBao;
public:
    GiangVien(){};
    GiangVien(char id, char DV, char name, int year, double hs, char subject, int hour, int news):Nguoi(id, DV,name,year,hs){
        monGiangDay = subject;
        soGio = hour;
        soBaiBao = news;
    }
    double PhuCap(){
        return 1200 * 0.25;
    }
    double LuongThang(){
        return PhuCap() + soGio * 200;
    }
    void input(){
        Nguoi::input();
        cout << endl;
        cout << "Nhap Mon Giang Day: "; cin >> monGiangDay;
        cout << "Nhap So Gio: "; cin >> soGio;
        cout << "Nhap So Bai Bao: "; cin >> soBaiBao;
    }
    void output(){
        Nguoi::output();
        cout << "Mon Giang Day: " << monGiangDay << "\t" << "SoGio: " << soGio << "\t" << "SoBaiBao: " << soBaiBao;
    }
};
class SinhVien : public Nguoi{
private:
    char Monhoc;
    int soTinChi;
    double diemQT;
public:
    SinhVien(){};
    SinhVien(char id, char DV, char name, int year, double hs, char subject, int Tinchi, double Diem):Nguoi(id, DV,name,year,hs){
        Monhoc = subject;
        soTinChi = Tinchi;
        diemQT = Diem;
    }
    double getDiemQT(){
        return diemQT;
    }
    void input(){
        Nguoi::input();
        cout << endl;
        cout << "Nhap Mon Hoc: "; cin >> Monhoc;
        cout << "Nhap So Tin Chi: "; cin >> soTinChi;
        cout << "Nhap Diem Qua Trinh: "; cin >> diemQT;
    }
    void output(){
        Nguoi::output();
        cout << endl;
        cout << "Mon Hoc: " << Monhoc << "\t" << "SoTinChi: " << soTinChi << "\t" <<"DiemQT: "<< diemQT;
    }
};
// selection sort
void sort(Nguoi  **list, int n){
    int i, max;
    for(i = 0; i < n - 1; i++){
        max = i;
        for(int j = 0; j < n; j++){
            if(dynamic_cast<GiangVien*>(list[i])->LuongThang() > dynamic_cast<GiangVien*>(list[max])->LuongThang()){
                max = j;
            }
        }
        if(i != max){
            Nguoi *temp = list[i];
            list[i] = list[max];
            list[max] = temp;
        }
    }
}
int main(){
    int n;
    do{
        cout << "Nhap N nguoi ( 0 < N <= 100 ): "; cin >> n;
    } while (n < 0 ||  n > 100);
    Nguoi *list[n];
    for(int i = 0; i < n; i++){
        int choice;
        cout << "Nhap Lua Chon ( 0 la Giang Vien, 1 la Sinh Vien ): "; cin >> choice;
        if(choice == 0){
            list[i] = new GiangVien;
            list[i]->input();
        } else if (choice == 1){
            list[i] = new SinhVien;
            list[i]->input();
        }
    }
    sort(list, n);
    for(int i = 0; i < n; i++){
        dynamic_cast<GiangVien*>(list[i])->output();
        cout << endl;
    }
    cout << "\nDanh Sach Sinh Vien Cam Thi: \n";
    for(int i = 0; i < n; i++){
        if(dynamic_cast<SinhVien*>(list[i])->getDiemQT() < 4){
            list[i]->output();
            cout << endl;
        }
    }
    return 0;
}