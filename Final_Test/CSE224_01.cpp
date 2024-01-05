#include<iostream>
#include<cmath>
using namespace std;
class CPoint{
private:
    double x, y;
public:
    CPoint(){};
    CPoint(double x, double y){
        this->x = x;
        this->y = y;
    }
    // setter
    void setX(double X){
        x = X;
    }
    void setY(double Y){
        y = Y;
    }
    void input(){
        cout << "Nhap X: "; cin >> x;
        cout << "Nhap Y: "; cin >> y;
    }
    void output(){
        cout << "X: " << x  << "\t" << "Y: " << y << endl;
    }
    void SangPhai(){
        setX(x+1);
    }
    friend double KhoangCach(CPoint A, CPoint B);
    bool ThangHang(CPoint A, CPoint B){
        double d1 = KhoangCach(*this, A);
        double d2 = KhoangCach(*this, B);
        double d3 = KhoangCach(A,B);
        return (d1 == d2 + d3 || d2 == d1 + d3 || d3 == d1 + d2);
    }
};
double KhoangCach(CPoint A, CPoint B){
    return (sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y,2)));
}
int main(){
    CPoint P1(2,3);
    CPoint P2;
    P2.input();
    cout << "\nP1: ";

    P1.output();
    cout << "\nP2: ";
    P2.output();
    cout << "\nKhoang Cach P1 Va P2: " << KhoangCach(P1,P2) << endl;
    P2.SangPhai();
    cout << "P2 sau khi dich sang phai 1 don vi: \n";
    P2.output();
    CPoint P3(4,5);
    cout << "\nP3: ";
    P3.output();
    if(P1.ThangHang(P2,P3)){
        cout << "Thang Hang";
    } else {
        cout << "Khong Thang Hang";
    }
    return 0;
}