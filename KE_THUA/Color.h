#ifndef PRINCIPLE_OOP_COLOR_H
#define PRINCIPLE_OOP_COLOR_H
#include<iostream>
namespace std{
    class Color{
    public:
        string TenMau, MaMau;
    public:
        Color(){};
        Color(string TenMau, string MaMau){
            this->TenMau = TenMau;
            this->MaMau = MaMau;
        }
        ~Color(){};
        friend ostream& operator<<(ostream&out , Color color);
        friend istream& operator>>(istream&in, Color& color);
        string getTenMau(){
            return this->TenMau;
        }
        string getMaMau(){
            return this->MaMau;
        }
    };
    ostream& operator<<(ostream&out, Color color){
        out << color.TenMau << "\t" << color.MaMau;
        return out;
    }
    istream& operator>>(istream&in, Color& color){
        in >> color.TenMau >> color.MaMau;
        return in;
    }
}
#endif //PRINCIPLE_OOP_COLOR_H
