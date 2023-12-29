#include<iostream>
using namespace std;
struct date{
    int ngay, thang, nam;
};
class VeMayBay{
private:
    string TenChuyen;
    date NgayBay;
    double GiaVe;
public:
    VeMayBay() : NgayBay(), GiaVe(){}; // Constructor
    ~VeMayBay(){}; // Destructor
    double getGiaVe(){
        return GiaVe;
    }
    void input(){
        cout << "Nhap Ten Chuyen Bay: "; cin >> TenChuyen;
        cout << "Nhap Ngay Bay: "; cin >> NgayBay.ngay >> NgayBay.thang >> NgayBay.nam;
        cout << "Nhap Gia Ve: "; cin >> GiaVe;
    }
    void output(){
        cout << "Chuyen: " << TenChuyen << "\t" << "Ngay Bay: " << NgayBay.ngay << "-" << NgayBay.thang << "-" << NgayBay.nam <<
        "\t"<< "Gia Ve: " << GiaVe << endl;
    }
};
class Nguoi{
protected:
    string HoTen, GioTinh;
    int Tuoi;
public:
    Nguoi() : Tuoi(){}; // Constructor
    ~Nguoi(){}; // Destructor
    virtual void input(){
        cout << "Nhap Ten: "; cin >> HoTen;
        cout << "Nhap Gio Tinh: "; cin >> GioTinh;
        cout << "Nhap Tuoi: "; cin >> Tuoi;
    }
    virtual void output(){
        cout << "Ten: " << HoTen << "\t"
        << "Gioi Tinh: " << GioTinh << "\t\t"
        << "Tuoi: " << Tuoi << endl;
    }
};
class HanhKhach: public Nguoi{
private:
    int SoLuong;
    VeMayBay **listVe;
public:
    HanhKhach(){}; // Constructor
    ~HanhKhach(){}; // Destructor
    void input(){
        Nguoi :: input();
        cout << "Nhap So Luong Ve: "; cin >> SoLuong;
        listVe = new VeMayBay*[SoLuong];
        for(int i = 0; i < SoLuong; i++){
            listVe[i] = new VeMayBay;
            listVe[i]->VeMayBay::input();
        }
    }
    void output(){
        Nguoi :: output();
        for(int i = 0; i < SoLuong; i++){
            listVe[i]->VeMayBay::output();
        }
    }
    double TongTien(){
        double sum = 0;
        for(int i = 0; i < SoLuong; i++){
            sum += listVe[i]->getGiaVe();
        }
        return sum;
    }
};
// Selecttion Sort
void SortGiaVe(HanhKhach *customter[], int size){
    int i, j , max;
    for( i = 0; i < size - 1 ; i++){
        max = i;
        for(j = i + 1; j < size; j++){
            if(customter[j]->TongTien() > customter[max]->TongTien()){
                max = j;
            }
        }
        if(i != max){
            HanhKhach *temp = customter[i];
            customter[i] = customter[max];
            customter[max] = temp;
        }
    }
}
int main(){
    int size;
    cout << "Nhap So Hanh Khach: "; cin >> size;
    HanhKhach* Customer[size];
    for (int i = 0; i < size; i++) {
        Customer[i] = new HanhKhach();
        Customer[i]->input();
    }
    SortGiaVe(Customer, size);
    cout << "\nDanh Sach Khach Hang Duoc Sap Xep Giam Dan Theo Tong Tien Ve:\n";
    for (int i = 0; i < size; i++) {
        Customer[i]->output();
        cout << "Tong Tien: " << Customer[i]->TongTien() << endl;
        cout << endl;
    }
    for (int i = 0; i < size; i++) {
        delete Customer[i];
    }
    return 0;
}
