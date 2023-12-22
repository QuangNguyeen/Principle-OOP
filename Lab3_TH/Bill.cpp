#include<iostream>
using namespace std;
class HoaDon{
protected:
    int soLuong;
    double giaCa;
public:
    HoaDon(){
        this->soLuong = 1;
        this->giaCa = 10;
    };
    HoaDon(int sl, double gc){
        this->soLuong = sl;
        this->giaCa = gc;
    };
    friend istream& operator>>(istream&in , HoaDon& Bill);
    double tongTien(){
        return soLuong*giaCa;
    };
    void setgiaCa(double gc){
        this->giaCa = gc;
    };
    virtual void inHoaDon(){
        cout << "So luong san pham: " << soLuong << "\t"
        << "Gia: " << giaCa <<"\t"
        << "Tong Tien: " << tongTien()
        << endl;
    }
};
istream& operator>>(istream&in , HoaDon& Bill){
    cout << "Nhap So Luong: "; in >> Bill.soLuong;
    cout << "Nhap Gia Ca: "; in >> Bill.giaCa;
    return in;
}
class HoaDonKM: public HoaDon{
private:
    double giamGia;
public:
    HoaDonKM(){
        this->soLuong = 1;
        this->giaCa = 10;
        this->giamGia = 2;
    };
    HoaDonKM(int sl, double gc, double gg){
        this->soLuong = sl;
        this->giaCa = gc;
        this->giamGia = gg;
    };
    friend istream& operator>>(istream&in , HoaDonKM& Bill_KM);
    double thanhToan(){
        return tongTien()-giamGia*soLuong;
    }
    void inHoaDon() {
        cout << "So luong san pham: " << soLuong << "\t"
             << "Gia: " << giaCa << "\t"
             << "Tong Tien: " << tongTien() << "\t"
             << "Giam gia: " << giamGia << "\t"
             << "Thanh Toan: " << thanhToan() << endl;
    }
};
istream& operator>>(istream&in , HoaDonKM& Bill_KM){
    cout << "Nhap So Luong: "; in >> Bill_KM.soLuong;
    cout << "Nhap Gia Ca: "; in >> Bill_KM.giaCa;
    cout << "Nhap Giam Gia: "; in >> Bill_KM.giamGia;
    return in;
}
int main(){
    int n;
    cout << "Nhap So Hoa Don KM: ";
    cin >> n;
    HoaDonKM Bill[n];
    for(int i = 0; i < n; i++){
        cin >> Bill[i];
    }
    for(int i = 0; i < n; i++){
        Bill[i].inHoaDon();
    }
    return 0;
}