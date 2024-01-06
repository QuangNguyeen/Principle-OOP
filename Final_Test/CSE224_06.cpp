#include<iostream>
using namespace std;
class Thuoc{
private:
    string maThuoc, tenThuoc, hangThuoc;
    double giaThuoc;
public:
    Thuoc(){};
    Thuoc(string id, string name, string firm, double price){
        maThuoc = id;
        tenThuoc = name;
        hangThuoc = firm;
        giaThuoc = price;
    }
    // getter
    string getMaThuoc(){
        return maThuoc;
    }
    string getTenThuoc(){
        return tenThuoc;
    }
    string getHangThuoc(){
        return hangThuoc;
    }
    // setter
    void setMaThuoc(string id){
        maThuoc = id;
    }
    void setTenThuoc(string name){
        tenThuoc = name;
    }
    void setHangThuoc(string firm){
        hangThuoc = firm;
    }
    void setGiaThuoc(double price){
        giaThuoc = price;
    }
    virtual void input(){
        cout << "Nhap Ma Thuoc: "; cin >> maThuoc;
        cout << "Nhap Ten Thuoc: "; cin >> tenThuoc;
        cout << "Nhap Hang Thuoc: "; cin >> hangThuoc;
        cout << "Nhap Gia Thuoc: "; cin >> giaThuoc;
    }
    virtual void output(){
        cout << "ID: " << maThuoc << "\t" << "Ten: " << tenThuoc << "\t" << "Hang: " << hangThuoc << "\t" << "Gia: " << giaThuoc;
    }
    bool operator == (const Thuoc & other) const{
        return this->maThuoc == other.maThuoc;
    }
};
class ThuocBo : public Thuoc {
private:
    string congDung;
public:
    // Constructor
    ThuocBo(){};
    ThuocBo(string id, string name, string firm, double price,string use):Thuoc(id,name,  firm,  price) {
        congDung = use;
    }
    // Destructor
    ~ThuocBo(){};
    // getter
    string getCongDung(){
        return congDung;
    }
    // setter
    void setCongDung(string use){
        congDung = use;
    }
    void input(){
        Thuoc::input();
        cout << "Nhap Cong Dung Cua Thuoc: "; cin >> congDung;
    }
    void output(){
        Thuoc::output();
        cout << "\tCongDung: " << congDung;
    }
};
class KhangSinh : public Thuoc {
private:
    string hamLuongSD;
public:
    // Constructor
    KhangSinh(){};
    KhangSinh(string hamLuong){
        hamLuongSD = hamLuong;
    }
    // Destructor
    ~KhangSinh(){};
    void input(){
        Thuoc::input();
        cout << "Nhap Ham Luong Su Dung: "; cin >> hamLuongSD;
    }
    void output(){
        Thuoc::output();
        cout << "\tHamLuongSD: " << hamLuongSD;
    }
};

int main(){
    int n;
    cout << "Nhap so luong thuoc: "; cin >> n;
    Thuoc *listMedicine[n];
    for(int i = 0; i < n;  i++){
        int choice;
        cout << "Chon loai thuoc: (0 la thuoc bo, 1 la thuoc khang sinh ): "; cin >> choice;
        if (choice == 0){
            listMedicine[i] = new ThuocBo;
            listMedicine[i]->input();
        } else if (choice == 1){
            listMedicine[i] = new KhangSinh;
            listMedicine[i]->input();
        }
    }
    cout << endl;
    cout << "\nThong Tin Danh Sach Thuoc: \n";
    for(int i = 0; i < n; i++){
        listMedicine[i]->output();
        cout << endl;
    }
    Thuoc *newMedicine;
    int choice;
    cout << "Thuoc moi la Thuoc Bo (0) hay KhangSinh ( 1) : "; cin >> choice;
    if(choice == 0){
        newMedicine = new ThuocBo;
        newMedicine->input();
    } else if (choice == 1){
        newMedicine = new KhangSinh;
        newMedicine->input();
    }
    bool checkExist = false;
    for(int i = 0; i < n; i++){
        if(*listMedicine[i] == *newMedicine){
            checkExist = true;
        }
    }
    if(checkExist == true){
        cout << "Thuoc co trong danh sach";
    } else {
        cout << "Thuoc chua ton tai trong danh sach";
    }
    return 0;
}