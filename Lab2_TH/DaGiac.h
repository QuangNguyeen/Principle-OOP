//
// Created by macbook on 05/12/2023.
//

#ifndef PRINCIPLE_OOP_DAGIAC_H
#define PRINCIPLE_OOP_DAGIAC_H
#include<iostream>
#include "Point.h"
#include<string>
namespace std {

    class DaGiac {
    private:
        Point a[100];
        double size;
    public:
        DaGiac(){}; //Constructor
        ~DaGiac(){}; //Destructor
        friend istream& operator>>(istream& in, DaGiac& daGiac);
        friend ostream& operator<<(ostream& out,DaGiac daGiac);
        friend bool KiemTra(DaGiac daGiac);
        friend bool KiemTraCan(DaGiac daGiac);
    };
    istream& operator>>(istream& in, DaGiac& daGiac){
        cout << "Nhap So Diem: ";
        in >> daGiac.size;
        for(int i = 0; i < daGiac.size; i++){
            cout << "Nhap Toa Do Diem: " << i + 1 << "(x, y ):";
            in >> daGiac.a[i];
        }
        return in;

    }
    ostream& operator<<(ostream& out, const DaGiac daGiac){
        out << "Da Giac co " << daGiac.size << " diem:" << endl;

        for (int i = 0; i < daGiac.size; ++i) {
            out << "Diem " << i + 1 << ": " << daGiac.a[i] << endl;
        }
        return out;
    }
    bool KiemTra(Point A, Point B, Point C){
        double AB, BC, AC;
        AB = KhoangCach(A,B);
        AC = KhoangCach(A,C);
        BC = KhoangCach(B,C);
        if(AB + BC > AC && AB + AC > BC && BC + AC > AB){
            return true;
        } else{
            return false;
        }
    }
    bool KiemTraCan(DaGiac daGiac){
        if(daGiac.size == 3 && KiemTra(daGiac.a[0], daGiac.a[1], daGiac.a[2])){
                if(KhoangCach(daGiac.a[0], daGiac.a[1]) == KhoangCach(daGiac.))
        }
    }

} // std

#endif //PRINCIPLE_OOP_DAGIAC_H
