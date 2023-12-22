#include<iostream>
using namespace std;
struct date{
    int ngay, thang, nam;
};
class VeMayBay{
private:
    string TenChuyen;
    date NgayBay;
    double GiaVe;
public:
    VeMayBay(){}; // Constructor
    ~VeMayBay(){}; // Destructor
    friend ostream& operator<<(ostream&out, VeMayBay ticket);
    friend istream& operator>>(istream&in, VeMayBay& ticket);
    void inputData(VeMayBay& ticket){
        cout << "Nhap thong tin chuyen bay: \n";
        cin >> ticket;
    }
    void outputData(VeMayBay ticket){
        cout << "Toan bo thong tin cua chuyen bay: \n";
        cout << ticket;
    }
    double getGiaVe(){
        return this->GiaVe;
    }
    date getNgayBay(){
        return this->NgayBay;
    }
};
ostream& operator<<(ostream&out, VeMayBay ticket){
    out << " Ten Chuyen: " << ticket.TenChuyen << "\t"
        << "Ngay Bay: " << ticket.NgayBay.ngay << "/" << ticket.NgayBay.thang << "/" << ticket.NgayBay.nam << "\t"
        << "Gia Ve: " << ticket.GiaVe ;
        return out;
}
istream& operator>>(istream& in, VeMayBay& ticket){
    cout << "Nhap Ten Chuyen: ";
    in >> ticket.TenChuyen;
    cout << "Nhap Ngay Bay: ";
    in >> ticket.NgayBay.ngay >> ticket.NgayBay.thang >> ticket.NgayBay.nam;
    cout << "Nhap Gia Ve: ";
    in >> ticket.GiaVe;
    return in;
}
class Nguoi{
protected:
    string HoTen, GioiTinh;
public:
    Nguoi(){}; // Constructor
    ~Nguoi(){}; // Destructor
    friend istream& operator>>(istream&in, Nguoi& people);
    friend ostream& operator<<(ostream&out, Nguoi people);
};
istream& operator>>(istream&in, Nguoi& people){
    cout << "Nhap HoTen Nguoi Bay: ";
    in >> people.HoTen;
    cout << "Nhap Gioitinh: ";
    in >> people.GioiTinh;
    return in;
}
ostream& operator<<(ostream&out, Nguoi people){
    cout << people.HoTen <<"\t" <<people.GioiTinh;
    return out;
}
class HanhKhach: public Nguoi{
private:
    int n;
    VeMayBay *ticket;
public:
    HanhKhach(): Nguoi(){
        cout << "Nhap So Chuyen Bay: ";
        ticket = new VeMayBay[n];
    }; // constructor
    ~HanhKhach(){}; // destructor
    friend istream& operator>>(istream&in, HanhKhach &HK);
    friend ostream& operator<<(ostream&out, HanhKhach HK);
    double TongTien(){
        double  sum = 0;
        int i = 0;
        while(i<n){
            sum += this->ticket[i].getGiaVe();
            i++;
        }
        return sum;
    }
};
istream& operator>>(istream&in, HanhKhach &HK){
    cout << "Nhap So Chuyen Bay: ";
    in >> HK.n;
    in >> HK.HoTen;
    in >> HK.GioiTinh;
    for(int i = 0; i < HK.n; i++){
        cout << "Nhap Thon Tin Chuyen Bay Thu" <<"\t" << i+1 << endl;
        in >> HK.ticket[i];
    }
    return in;
}
ostream& operator<<(ostream&out, HanhKhach HK){
    out << HK.HoTen <<"\t" <<HK.GioiTinh << endl;
    int i = 0;
    while(HK.ticket[i].getNgayBay().ngay != 0){
        out << HK.ticket[i] << endl;
        i++;
    }
    return out;
}
int main(){
    int n;
    cout << "Nhap So Hanh Khach: ";
    cin >> n;
    HanhKhach HK[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap Thong Tin Khach Thu " << i+1 << endl ;
        cin >> HK[i];
    }
    cout << "Display Information: \n";
    for(int i = 0; i < n; i++){
        cout << HK[i];
        cout << endl;
    }
    return 0;
}
