#include<iostream>
#include<vector>
using namespace  std;
class HoaQua{
private:
    string MaHQ, TenHQ, XuatXu;
    double Gia,  ThanhTien;
public:
    // Constructor
    HoaQua(){};
    HoaQua(string id, string name, string xuatxu, double price){
        MaHQ = id;
        TenHQ = name;
        XuatXu = xuatxu;
        Gia = price;
        ThanhTien = 0;
    }
    // Destructor
    ~HoaQua(){};
    // getter
    string getMaHQ(){
        return MaHQ;
    }
    string getTenHQ(){
        return TenHQ;
    }
    string getXuatXu(){
        return XuatXu;
    }
    double getGiaTien(){
        return Gia;
    }
    double getThanhTien(){
        return ThanhTien;
    }
    // setter
    void setMaHQ(string id){
        MaHQ = id;
    }
    void setTenHQ(string name){
        TenHQ = name;
    }
    void setXuatXu(string xuatxu){
        XuatXu = xuatxu;
    }
    void setGiaTien(double price){
        Gia = price;
    }
    virtual void setThanhTien(double money){
        ThanhTien = money;
    }
    virtual void input(){
        cout << "Nhap Ma Hoa Qua: "; cin >> MaHQ;
        cout << "Nhap Ten Hoa Quan: "; cin >> TenHQ;
        cout << "Nhap Xuat Xu: "; cin >> XuatXu;
        cout << "Nhap Gia: "; cin >> Gia;
    }
    virtual void output(){
        cout << "ID: " << MaHQ << "\t" << "Ten: " << TenHQ << "\t"
        << "XuatXu: " << XuatXu << "\t" << "Gia: " << Gia;
    }
    // Override operator
    HoaQua operator + (HoaQua other){
        HoaQua result;
        result.ThanhTien = this->ThanhTien + other.ThanhTien;
        return result;
    }
};
class DuaHau : public HoaQua{
private:
    double KhoiLuong;
public:
    // Constructor
    DuaHau(){};
    DuaHau(double kg){
        KhoiLuong = kg;
    }
    // Destructor
    ~DuaHau(){};
    // getter
    double getKhoiLuong(){
        return KhoiLuong;
    }
    // setter
    void setKhoiLuong(double kg){
        KhoiLuong = kg;
    }
    void setThanhTien(){
        HoaQua::setThanhTien(getKhoiLuong()*getGiaTien());
    }
    void input(){
        HoaQua::input();
        cout << "Nhap Khoi Luong: "; cin >> KhoiLuong;
        setThanhTien();
    }
    void output(){
        HoaQua::output();
        cout << endl;
        cout <<"KhoiLuong: "<< KhoiLuong << "\t" <<"ThanhTien: " << getThanhTien();
    }
};
class QuaDua : public HoaQua{
private:
    int SoLuong;
public:
    //Constructor
    QuaDua(){};
    QuaDua(int number){
        SoLuong = number;
    }
    // Destructor
    ~QuaDua(){};
    void setThanhTien(){
        HoaQua::setThanhTien(getGiaTien() * SoLuong);
    }
    void input(){
        HoaQua::input();
        cout << "Nhap So Luong: "; cin >> SoLuong;
        setThanhTien();
    }
    void output(){
        HoaQua::output();
        cout << "\n";
        cout << "SoLuong: " << SoLuong << "\t" << "ThanhTien: " << getThanhTien();
    }
};
int main(){
    int n;
    cout << "Nhap N Hoa Qua: "; cin >> n;
    HoaQua *list[n];
    for(int i = 0; i < n ; i++){
        int choice;
        cout << "Nhap Loai Hoa Qua: ( 0 la Dua Hau, 1 la Dua ): "; cin >> choice;
        if(choice == 0){
            list[i] = new DuaHau;
            list[i]->input();
        } else if(choice == 1){
            list[i] = new QuaDua;
            list[i]->input();
        }
    }
    cout << "\n";
    cout << "Thong Tin Don Hang:\n";
    HoaQua sum;
    for(int i = 0; i < n; i++){
        cout << "Qua Thu "  << i + 1 <<": "<< endl;
        sum = sum + *list[i];
        list[i]->output();
        cout << endl;
    }
    cout << "\nTongTien: " << sum.getThanhTien();
    return 0;
}