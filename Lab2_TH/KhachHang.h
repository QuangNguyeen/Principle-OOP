//
// Created by macbook on 07/12/2023.
//
#ifndef PRINCIPLE_OOP_KHACHHANG_H
#define PRINCIPLE_OOP_KHACHHANG_H
#include<iostream>
#include "MatHang.h"
namespace  std{
    class KhachHang {
    private:
        int MaKH;
        string HoTen;
        string DiaChi;
        string SDT;
        string LoaiKH;// true la mua le, false la mua buon
    public:
        KhachHang(){
            this->MaKH = 10000;
        }
        int getMaKH(){
            return MaKH;
        }
        friend ostream& operator<<(ostream& out , KhachHang KhachHang);
        friend istream& operator>>(istream& in, KhachHang& KhacHang);
    };
    ostream& operator<<(ostream& out , KhachHang KhachHang){
        out << endl;
        out << KhachHang.MaKH << "\t"
            << KhachHang.HoTen<< "\t"
            << KhachHang.DiaChi << "\t"
            << KhachHang.LoaiKH <<"\t"
            <<KhachHang.SDT << endl;
        return out;
    }
    istream& operator>>(istream& in, KhachHang& KhachHang){
        cout << "\nNhap MaKH: "; in >> KhachHang.MaKH;
        cout << "Nhap Ho Ten: "; in >> KhachHang.HoTen;
        cout << "Nhap Dia Chi: "; in >> KhachHang.DiaChi;
        cout << "Nhap Loai KH: "; in >> KhachHang.LoaiKH;
        cout << "Nhap SDT: "; in >> KhachHang.SDT;
        return in;
    }
}

#endif //PRINCIPLE_OOP_KHACHHANG_H
