#include<iostream>
#include<vector>
using namespace std;
class MatHang{
private:
    static int maMatHangCounter;
    int maMatHang;
    string tenHang;
    string nhomHang;
    double giaBan;
public:
    MatHang(string name, string group, double price){
        maMatHang = ++maMatHangCounter;
        tenHang   = name;
        nhomHang  = group;
        giaBan    = price;
    }
    int getMaHang(){
        return maMatHang;
    }
    virtual void input(){
        cout << "Nhap Ten Mat Hang: ";  cin >> tenHang;
        cout << "Nhap Nhom Hang: ";     cin >> nhomHang;
        cout << "Nhap Gia Ban: ";       cin >> giaBan;
    }
    virtual void output(){
        cout << "Ten Hang: " << tenHang << "\t" << "Nhom: " << nhomHang << "\t" << "Gia: " << giaBan << endl;
    }
};
class Nguoi{
protected:
    string hoTen;
    string diaChi;
    string SDT;
};
class KhachHang: public Nguoi{
private:
    static int maKHCounter;
    int maKH;
    int soMatHang;
    string loaiKH;
    vector<int> listMatHang;
public:
    KhachHang(string name, string address, string phone, int soMH, string type){
        hoTen   = name;
        diaChi  = address;
        SDT     = phone;
        maKH    = ++ maKHCounter;
        soMatHang = soMH;
        loaiKH  = type;
    }
    int getMaKH(){
        return maKH;
    }
    int getSoMatHang(){
        return soMatHang;
    }
    vector<int> getListHang(){
        return listMatHang;
    }
    void input(){
        cout << "Nhap Ten KH: "; cin >> hoTen;
        cout << "Nhap Dia Chi: "; cin >> diaChi;
        cout << "Nhap SDT: "; cin >> SDT;
        cout << "Nhap So Mat Hang Da Mua: "; cin >> soMatHang;
        cout << "Nhap Loai Khach Hang: "; cin >> loaiKH;
        for(int i = 0; i < soMatHang; i++){
            int temp;
            cout << "Nhap Ma Hang Da Mua Thu " << i + 1 << ": "; cin >> temp;
            if(temp >= 1000){
                listMatHang.push_back(temp);
            } else {
                i--;
                cout << "Ma Khong Hop Le";
            }
        }
    }
    void output(){
        cout << "Ten: " << hoTen << "\t" << "Dia Chi: " << diaChi << "\t" << "SDT: " << SDT  << endl;
        cout  << "Loai KH: " << loaiKH << "\t" << "So Mat Hang Da Mua: " << soMatHang << endl;
        cout << "Danh Sach Ma Hang Da Mua: \n";
        for(int i : listMatHang){
            cout << i << endl;
        }
    }
};
void addKhachHang(vector<KhachHang> &KH){
    KhachHang temp("name","address","phone",0,"type");
    temp.input();
    KH.push_back(temp);
}
void timKH(vector<KhachHang> KH, int id, vector<MatHang> Hang){
    int size = KH.size(), i = 0;
    bool checkExist = false;
    for(i = 0; i < size; i++){
        if(id == KH[i].getMaKH()){
            KH[i].output();
            cout << "\nThong Tin Chi Tiet Cac Mat Hang Da Mua: \n";
            for(int j = 0; i < KH[i].getSoMatHang(); j++ ){
                for(int k = 0; k < Hang.size(); k++){
                    if(KH[i].getListHang()[j] == Hang[k].getMaHang()){
                        Hang[k].output();
                        cout << endl;
                    }
                }
            }
            checkExist = true;
        }
    }
    if(checkExist){
        cout << "Khach Hang Chua Ton Tai. " << endl;
        addKhachHang(KH);
    }
}
int MatHang::maMatHangCounter = 999;
int KhachHang::maKHCounter = 9999;
int main(){
    vector<MatHang> Hang;
    vector<KhachHang> KH;
    int n, m;
    cout << "Nhap Tong So Mat Hang Dang Ban O Market\n"; cin >> n;
    for(int i = 0; i < n; i++){
        MatHang temp("name", "group",0);
        temp.input();
        Hang.push_back(temp);
    }
    cout << "Nhap So Khach Hang: "; cin >> m;
    for(int i = 0; i < m; i++){
        KhachHang client("name","address","phone",0, "type");
        client.input();
        KH.push_back(client);
    }
    int idKH;
    cout << "Nhap Ma Khach Hang Can Tim Kiem: "; cin >> idKH;
    timKH(KH, idKH, Hang);
    return 0;
}
