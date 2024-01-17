#include<iostream>
using namespace std;
struct Date{
    int ngay, thang, nam;
};
class ThietBi{
private:
    int id;
    string name, manufacturer;
    Date importedDate;
public:
    // Constructor
    ThietBi(){};
    ThietBi(int ma, string ten,  string hangSX, Date ngay){
        id = ma;
        name = ten;
        manufacturer = hangSX;
        importedDate = ngay;
    }
    // getter
    int getID(){
        return id;
    }
    string getNAME(){
        return name;
    }
    string getManufacturer(){
        return manufacturer;
    }
    Date getDATE(){
        return importedDate;
    }
    // setter
    void setID(int ma){
        id = ma;
    }
    void setNAME(string ten){
        name = ten;
    }
    void setManufacturer(string hangSX){
        manufacturer = hangSX;
    }
    void setDATE(Date ngayHetHan){
        importedDate = ngayHetHan;
    }
    // virtual function
    virtual unsigned long printPrice() const  = 0;
    virtual void input(){
        cout << "Nhap ID: "; cin >> id;
        cout << "Nhap Ten Thiet Bi: "; cin >> name;
        cout << "Nhap Hang San Xuat: "; cin >> manufacturer;
        cout << "Nhap Ngay Het Han: "; cin >> importedDate.ngay >> importedDate.thang >> importedDate.nam;
    }
    virtual void output() const {
        cout << "ID: " << id << "\t" << "Name: " << name << "\t" << "Manufacturer: " << manufacturer
        << "\t" << "Imported Date: " << importedDate.ngay << "-" << importedDate.thang << "-" << importedDate.nam;
    }
    friend istream & operator >> (istream & in, ThietBi & device){
        device.input();
        return in;
    }
    friend ostream & operator << (ostream & out, const ThietBi & device){
        device.output();
        return out;
    }
    // 1 la ManHinh, 2 la MayTinh
//    int getType() const {
//        if(printPrice() == 500000){
//            return 1;
//        } else if(printPrice() == 15000000){
//            return 2;
//        }
//    }
    int getType();
};
class MayTinh : public ThietBi {
private:
    string cpu, ram;
public:
    // Constructor
    MayTinh(){};
    MayTinh(int ma, string ten,  string hangSX, Date ngay, string CPU, string RAM) : ThietBi(ma, ten, hangSX, ngay){
        cpu = CPU;
        ram = RAM;
    }
    // redefine the  virtual function
    unsigned long printPrice() const {
        return 15000000;
    }
    void input(){
        ThietBi::input();
        cout << "Nhap CPU: "; cin  >> cpu;
        cout << "Nhap RAM: "; cin >> ram;
    }
    void output() const {
        ThietBi::output();
        cout << "\t" << "CPU: " << cpu << "\t" << "RAM: " << ram << printPrice();
    }
    friend  istream & operator >> (istream & in, MayTinh & computer){
        computer.input();
        return in;
    }
    friend ostream & operator << (ostream & out, const MayTinh & computer){
        computer.output();
        return out;
    }
};
class ManHinh : public  ThietBi {
private:
    string size;
public:
    // Constructor
    ManHinh(){};
    ManHinh(int ma, string ten,  string hangSX, Date ngay, string donvi): ThietBi(ma, ten, hangSX, ngay){
        size = donvi;
    }
    unsigned long printPrice() const {
        return 500000;
    }
    // redefine the  virtual function
    void input(){
        ThietBi::input();
        cout << "Nhap Don Vi: "; cin >> size;
    }
    void output() const{
        ThietBi::output();
        cout << "\t" << "Size: " << size << "\t" << printPrice();
    }
    friend istream & operator >> (istream & in, ManHinh & screen){
        screen.input();
        return in;
    }
    friend ostream & operator << (ostream & out, const ManHinh & screen){
        screen.output();
        return out;
    }
};

int ThietBi::getType(){
    {
        if(dynamic_cast<ManHinh*>(this)){
            return 1 ;
        } else if(dynamic_cast<MayTinh*>(this)){
            return 2;
        }
    }
}
int main(){
    int n;
    do{
        cout << "Nhap N Thiet Bi ( 0 < N < 10 ) : "; cin >> n;
    } while (n <= 0 || n >= 10);
    ThietBi *listDevice[n];
    // input information of Device
    for(int i = 0; i < n; i++){
        int choice;
        cout << "Chon Loai Thiet Bi ( 1 la Man Hinh, 2 la May Tinh ): "; cin >> choice;
        if(choice == 1){
            listDevice[i] = new ManHinh;
            cin >> *listDevice[i];
        } else if (choice == 2){
            listDevice[i] = new MayTinh;
            cin >> *listDevice[i];
        }
    }
    cout << endl;
    // Display information of List Device
    for(int i = 0; i < n; i++){
        cout << *listDevice[i];
        cout << endl;
    }

    // Count the number of Computer, Screen
    int countComputer = 0, countScreen = 0;
    for(int i = 0; i < n; i++){
        if(listDevice[i]->getType() == 1){
            countScreen++;
        }else if(listDevice[i]->getType() == 2){
            countComputer++;
        }
    }
    cout << "So Man Hinh: " << countScreen;
    cout << "\nSo May Tinh: " << countComputer;
    return 0;
}
