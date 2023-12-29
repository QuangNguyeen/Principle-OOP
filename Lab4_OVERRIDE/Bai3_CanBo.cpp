#include<iostream>
using namespace std;
class CanBo{
protected:
    string HoTen;
    string GioiTinh;
    int NamSinh;
public:
    CanBo() : NamSinh(){};
    int Tuoi(){
        return 2023 - this->NamSinh;
    }
    virtual void input(){
        cout << "Nhap Ho Ten: "; cin >> HoTen;
        cout << "Nhap Gioi Tinh: "; cin >> GioiTinh;
        cout << "Nhap Nam Sinh: "; cin >> NamSinh;
    };
    virtual void output(){
        cout << "HoTen: " << "\t" << HoTen << "\t" << "GioiTinh: " << GioiTinh << "Tuoi: " << Tuoi();
    };
    virtual bool NghiHuu() = 0;
    virtual double Luong() = 0;
};
class BienChe : public CanBo{
private:
    string DonVi;
    double HSLuong;
public:
    BienChe() : HSLuong(){}; // Constructor
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
        CanBo :: input();
        cout << "Nhap Don Vi: ";
        cin >> DonVi;
        cout << "Nhap He So Luong: ";
        cin >> HSLuong;
    }
    void output(){
        CanBo::output();
        cout <<"\t"<< DonVi << "\t"<< HSLuong << endl;
        if(NghiHuu()){
            cout << "Da Nghi Huu \t";
        } else {
            cout << "Chua Nghi Huu \t";
        }
        cout << Luong();
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
        CanBo::input();
        cout << "Nhap Muc Luong: ";
        cin >> mucLuong;
        cout << "Nhap He So Tham Nien: ";
        cin >> heSoThamNien;
    }
    void output(){
       CanBo::output();
       cout << mucLuong<< "\t" << heSoThamNien << endl;
       if(NghiHuu()){
           cout << "Da Nghi Huu \t";
       } else {
           cout << "Chua Nghi Huu \t";
       }
       cout << Luong();
    }
};
int main(){
    cout << "Hai Can Bo\n";
    CanBo *listCanBo[2];
    cout << "Bien Che: \n";
    listCanBo[0] = new BienChe;
    listCanBo[0]->input();
    cout << "\nHop Dong: \n";
    listCanBo[1] = new HopDong;
    listCanBo[1]->input();
    cout << endl;
    listCanBo[0]->output();
    cout << "\n";
    listCanBo[1]->output();
    return 0;
}
