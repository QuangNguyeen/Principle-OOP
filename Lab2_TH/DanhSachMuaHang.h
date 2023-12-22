//
// Created by macbook on 07/12/2023.
//

#ifndef PRINCIPLE_OOP_DANHSACHMUAHANG_H
#define PRINCIPLE_OOP_DANHSACHMUAHANG_H
#include<iostream>
#include<vector>
#include "MatHang.h"
#include "KhachHang.h"
namespace std {
    // relationship: Association
    class DanhSachMuaHang {
    private:
        vector<MatHang> Hang;
        KhachHang KH;
    public:
        friend ostream &operator<<(ostream &out, DanhSachMuaHang List);
        friend istream &operator>>(istream &in, DanhSachMuaHang& List);
        vector<MatHang> getMaHang(){
            return this->Hang;
        }
        KhachHang getKhachHang(){
            return this->KH;
        }
        MatHang setMatHang(MatHang A, int index){
            this->Hang[index] = A;
        }
        KhachHang setKhachHang(KhachHang B){
            this->KH = B;
        }

    };
    ostream &operator<<(ostream &out, DanhSachMuaHang List){
        out << "Danh sach mua hang: " << endl;
        out << List.KH;
        int i;
        for(i = 0; i < List.Hang.size(); i++){
            cout << List.Hang[i];
        }
        return out;
    }
    istream &operator>>(istream &in, DanhSachMuaHang& List){
        cout <<"Nhap Khach Hang: " << List.KH;
        return in;
    }
} // std

#endif //PRINCIPLE_OOP_DANHSACHMUAHANG_H
