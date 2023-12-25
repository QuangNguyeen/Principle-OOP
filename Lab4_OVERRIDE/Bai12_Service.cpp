#include<iostream>
#include<vector>
using namespace std;
class DichVu{
private:
    static int maDVCounter;
    int maDV;
    string tenDV;
    double giaCuoc;
    string donViTinh;
public:
    // Constructor
    DichVu(){
        maDV = ++maDVCounter;
    }
    void input(){
        cout << "Nhap Ten Dich Vu: "; cin >> tenDV;
        cout << "Nhap Gia Cuoc Cua Dich Vu: "; cin >> giaCuoc;
        cout << "Nhap Don Vi Tinh: "; cin >> donViTinh;
    }
    friend class KhachHang;
};
class Nguoi{
protected:
    string hoTen;
    string diaChi;
    string SDT;
};
class KhachHang : Nguoi{
private:
    static int maKHCounter;
    int maKH;
    int soDichVu;
    vector<int> DanhSachMaDV;
public:
    KhachHang(){
        maKH = ++maKHCounter;
    }
    void input(){
        cout << "Nhap Ho Ten: "; cin >> hoTen;
        cout << "Nhap Dia Chi: "; cin >> diaChi;
        cout << "Nhap SDT: "; cin >> SDT;
        cout << "Nhap Tong So Dich Vu: "; cin >> soDichVu;
        for(int i = 0; i < soDichVu; i++){
            int temp;
            cout << "Nhap Ma Dich Vu " << i + 1 << ": "; cin >> temp;
            if(temp >= 100){
                DanhSachMaDV.push_back(temp);
            } else {
                cout << "Ma Dich Vu Khong Hop Le. Nhap Lai.";
                i--;
            }
        }
    }
    void output(){
        cout <<"Ma KH:"<< maKH << "\t" <<"Ten:" << hoTen << "\t" << "Dia Chi:" << diaChi <<"\t"<< "SDT:" << SDT << endl;
        cout <<"So Dich Vu Dang Su Dung: " << soDichVu << endl;
        cout <<"Danh Sach Ma Dich Vu Dang Su Dung: " << endl;
        for(int i = 0; i < soDichVu; i++){
            cout << DanhSachMaDV[i] << "\t";
        }
    }
    double getTongGiaCuoc(vector<DichVu> Service){
        double sum = 0;
        for(int i = 0; i < soDichVu; i++){
            for(int j = 0; j < Service.size(); j++){
                if(DanhSachMaDV[i] == Service[j].maDV){
                    sum += Service[j].giaCuoc;
                }
            }
        }
        return sum;
    }
};
// Sap Xep Khach Hang theo Tong Gia Cac Su dung Giam Dan
void sortKhachHang(vector<DichVu> Service, vector<KhachHang> &Customer){
    int i, j, max;
    for(i = 0; i < Customer.size() - 1; i++){
        max = i;
        for(j = i + 1; j < Customer.size(); j++){
            if(Customer[j].getTongGiaCuoc(Service) > Customer[i].getTongGiaCuoc(Service)){
                max = j;
            }
        }
        if(max != i){
            KhachHang temp = Customer[i];
            Customer[i] = Customer[max];
            Customer[max] = temp;
        }
    }

}
int DichVu::maDVCounter = 99;
int KhachHang::maKHCounter = 9999;
int main(){
    vector<DichVu> Service;
    vector<KhachHang> Customer;
    int sv, cs;
    cout << "Nhap So Dich Vu Dang Cung Cap: "; cin >> sv;
    for(int i = 0; i < sv; i++){
        DichVu temp;
        temp.input();
        Service.push_back(temp);
    }
    cout << "\n";
    cout << "Nhap So Khach Hang: "; cin >> cs;
    for(int i = 0; i < cs; i++){
        KhachHang temp;
        temp.input();
        Customer.push_back(temp);
    }
    // Sap Xep
    sortKhachHang(Service,Customer);
    // Xuat Thong Tin
    cout << "Danh Sach Khach Hang Sap Xep Theo Tong Gia Cuoc Giam Dan:\n";
    for(int i = 0; i < Customer.size(); i++){
        Customer[i].output();
        cout <<"\nTong gia cuoc: " << Customer[i].getTongGiaCuoc(Service) << endl;
    }
    return 0;
}
