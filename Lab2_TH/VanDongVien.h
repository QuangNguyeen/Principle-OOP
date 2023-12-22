//
// Created by macbook on 05/12/2023.
//

#ifndef PRINCIPLE_OOP_VANDONGVIEN_H
#define PRINCIPLE_OOP_VANDONGVIEN_H
#include<iostream>
using namespace std;

class VanDongVien {
private:
    string hoTen;
    int tuoi;
    string monThiDau;
    double canNang;
    double chieuCao;
public:
    VanDongVien(){};
    VanDongVien(string hoTen, int tuoi, string monThiDau, double canNang, double chieuCao){
        this->hoTen = hoTen;
        this->tuoi = tuoi;
        this->monThiDau = monThiDau;
        this->canNang = canNang;
        this->chieuCao = chieuCao;
    }
    ~VanDongVien(){};
    friend ostream& operator<<(ostream& out, const VanDongVien athlete);
    friend istream& operator>>(istream& in, VanDongVien& athlete);
    bool operator > (VanDongVien athlete){
        if(this->chieuCao > athlete.chieuCao){
            return true;
        } else if (this->chieuCao == athlete.chieuCao){
            if(this->canNang > athlete.canNang){
                return true;
            }
        }
        return false;
    }
};
ostream& operator<<(ostream& out, const VanDongVien athlete){
    out << athlete.hoTen <<"\t"<<athlete.tuoi <<"\t" <<athlete.monThiDau << "\t"<<athlete.canNang << "\t"<<athlete.chieuCao << endl;
    return out;
}
istream& operator>>(istream& in, VanDongVien &athlete){
    cout << "Nhap Ten: "; in >> athlete.hoTen;
    cout << "Nhap Tuoi: "; in >> athlete.tuoi;
    cout << "Nhap Mon Thi Dau: "; in >> athlete.monThiDau;
    cout << "Nhap Can Nang: "; in >> athlete.canNang;
    cout << "Nhap Chieu Cao: "; in >> athlete.chieuCao;
    return in;
}

#endif //PRINCIPLE_OOP_VANDONGVIEN_H