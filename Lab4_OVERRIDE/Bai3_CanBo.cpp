#include<iostream>
using namespace std;
class CanBo{
protected:
    string HoTen;
    string GioiTinh;
    int NamSinh;
public:
    CanBo(){};
    void setHoTen(string HoTen){
        this->HoTen = HoTen;
    }
    void setGioiTinh(string GioiTinh){
        this->GioiTinh = GioiTinh;
    }
    void setNamSinh(int namsinh){
        this->NamSinh = namsinh;
    }
    string getHoTen(){
        return HoTen;
    }
    string getGioTinh(){
        return GioiTinh;
    }
    int getNamSinh(){
        return NamSinh;
    }
    friend istream& operator>>(istream& in, CanBo& canBo);
    friend ostream& operator<<(ostream& out, CanBo& canBo);
    virtual void input(){};
    virtual void output(){};
    int Tuoi(){
        return 2023 - this->NamSinh;
    }
    virtual bool NghiHuu(){};
    virtual double Luong(){};
};
istream& operator>>(istream& in, CanBo& canBo){
    cout << "Nhap Ho Ten: "; in >> canBo.HoTen;
    cout << "Nhap Gioi Tinh: "; in >> canBo.GioiTinh;
    cout << "Nhap Nam Sinh: "; in >> canBo.NamSinh;
    return in;
}
ostream& operator<<(ostream& out, CanBo& canBo){
    out << "HoTen: " << "\t" << canBo.HoTen << "\t" << "GioiTinh: " << canBo.GioiTinh << "NamSinh: " << canBo.NamSinh;
    return out;
}
class BienChe : public CanBo{
private:
    string DonVi;
    double HSLuong;
public:
    BienChe(){}; // Constructor
    bool NghiHuu(){
        return (Tuoi() >= 60);
    }
    double Luong(){
        if(!NghiHuu()){
            return HSLuong*1310000;
        } else{
            return HSLuong*1310000*0.7;
        }
    }
    void input(){
        cout << "Nhap Ho Ten: ";
        cin >> this->HoTen;
        cout << "Nhap GioiTinh: ";
        cin >> this->GioiTinh;
        cout << "Nhap Nam Sinh: ";
        cin >> this->NamSinh;
        cout << "Nhap Don Vi: ";
        cin >> this->DonVi;
        cout << "Nhap He So Luong: ";
        cin >> this->HSLuong;
    }
    void output(){
        cout << this->HoTen << "\t"
        << this->GioiTinh <<"\t"
        << this->NamSinh << "\t"
        << this->DonVi << "\t"
        << this->HSLuong << endl;
    }
};
class HopDong: public CanBo{
private:
    int namCongTac;
    double heSoThamNien;
    double mucLuong;
public:
    HopDong(){};
    ~HopDong(){};
    friend istream& operator>>(istream& in, HopDong& hopDong);
    friend ostream& operator<<(ostream& out, HopDong& hopDong);
    bool NghiHuu(){
        return (namCongTac >= 35);
    }
    double Luong(){
        if(!NghiHuu()){
            return heSoThamNien*mucLuong;
        } else {
            return 0;
        }
    }
    void input(){
        cout << "Nhap Ho Ten: ";
        cin >> this->HoTen;
        cout << "Nhap GioiTinh: ";
        cin >> this->GioiTinh;
        cout << "Nhap Nam Sinh: ";
        cin >> this->NamSinh;
        cout << "Nhap Muc Luong: ";
        cin >> this->mucLuong;
        cout << "Nhap He So Tham Nien: ";
        cin >> this->heSoThamNien;
    }
    void output(){
        cout << this->HoTen << "\t"
             << this->GioiTinh <<"\t"
             << this->NamSinh << "\t"
             << this->mucLuong<< "\t"
             << this->heSoThamNien << endl;
    }
};
int main(){
    CanBo *canBo1 = new BienChe;
    CanBo *canBo2 = new HopDong;
    canBo1->input();
    canBo1->output();
    cout << endl;
    canBo2->input();
    canBo2->output();
    return 0;
}
