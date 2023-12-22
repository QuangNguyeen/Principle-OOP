//
// Created by macbook on 07/12/2023.
//

#ifndef PRINCIPLE_OOP_MATHANG_H
#define PRINCIPLE_OOP_MATHANG_H
#include<iostream>
namespace std {
    class MatHang {
    private:
        int MaH;
        string TenHang;
        string NhomH;
        double Gia;
    public:
        MatHang(){
            this->MaH = 1000;
        }
        int getMaH(){
            return MaH;
        }
        string getTenHang(){
            return TenHang;
        }
        string getNhomH(){
            return NhomH;
        }
        double getGia(){
            return Gia;
        }
        void setMaH(int Ma){
            this->MaH++;        // Tu dong tang
        }
        void setTenHang(string TenHang){
            this->TenHang = TenHang;
        }
        void setNhomH(string NhomH){
            this->NhomH = NhomH;
        }
        void setGia(double  Gia){
            this->Gia = Gia;
        }
        friend ostream& operator<<(ostream& out , MatHang Hang);
        friend istream& operator>>(istream& in, MatHang& Hang);
    };
    ostream& operator<<(ostream& out , MatHang Hang){
        out << endl;
        out << Hang.MaH << "\t" << Hang.TenHang
            << "\t" << Hang.NhomH << "\t" << Hang.Gia;
        return out;
    }
    istream& operator>>(istream& in, MatHang& Hang){
        cout << "\nNhap MaH: "; in >> Hang.MaH;
        cout << "Nhap TenHang: "; in >> Hang.TenHang;
        cout << "Nhap NhomH: "; in >> Hang.NhomH;
        cout << "Nhap Gia: "; in >> Hang.Gia;
        return in;
    }
} // std

#endif //PRINCIPLE_OOP_MATHANG_H
