#include<iostream>
#include<vector>
using namespace std;
class PhongBan{
private:
    static int maPhongBanCounter;
    int maPhongBan;
    string tenPhong;
    string moTa;
    double heSoCV;
public:
    // Constructor
    PhongBan(string name, string describe, int coefficients){
        maPhongBan = ++maPhongBanCounter;
        tenPhong = name;
        moTa = describe;
        heSoCV = coefficients;
    }
    virtual void input(){
        cout<<"Nhap Ten Phong Ban: ";       cin>>tenPhong;
        cout<<"Nhap Mo Ta Ve Phong Ban: ";  cin>>moTa;
        cout<<"Nhap He So Cong Viec: [ 1 - 20 ]: ";
        double heSo; cin >> heSo;
        if((heSo >= 1) && (heSo <= 20)){
            heSoCV = heSo;
        } else {
            cout << "He So Khong Hop Le. Quay Ve 1:";
            heSoCV = 1;
        }
    }
    friend class NhanVien;
};
class NhanVien{
private:
    static int maNVCounter;
    int maNV;
    int maPhong;
    string tenNV;
    int bacLuong;
    int soNgayCT;
public:
    //Constructor
    NhanVien(string name, int department, int rank, int workdays){
        maNV = ++maNVCounter;
        tenNV = name;
        maPhong = department;
        bacLuong = rank;
        soNgayCT = workdays;
    }
    int getMaNV() const{
        return maNV;
    }

    void input(){
        cout << "Nhap Ten Nhan Vien: ";     cin >> tenNV;
        cout << "Nhap Ma Phong Ban: ";      cin >> maPhong;
        cout << "Nhap So Ngay Cong Tac: ";  cin >> soNgayCT;
        int rank;
        cout << "Nhap Bac Luong: ";         cin >> rank;
        if( rank >= 1 && rank <= 9){
            bacLuong = rank;
        } else {
            cout << "Bac luong khong hop le. Quay ve Bac 1.";
            bacLuong = 1;
        }
    }
    void output(){
        cout << "MaNV: " << maNV << "\t" << "MaPB: " << maPhong << endl;
        cout << "Ten: " << tenNV << "\t" << "Bac Luong: " << bacLuong << "\t" << "So Ngay CT: " << soNgayCT << endl;
    }
    void output(vector<PhongBan> PB){
        int size = PB.size();
        for(int i = 0; i < size; i++){
            if(this->maPhong == PB[i].maPhongBan){
                cout << "Ma Nhan Vien: " << maNV << endl;
                cout << "Ten Nhan Vien: " << tenNV << endl;
                cout << "Ten Phong: " << PB[i].tenPhong << endl;
                cout << "He So Cong Viec: " << PB[i].heSoCV << endl;
                cout << "So Ngay Cong: " << soNgayCT;
            }
        }
    }
};
void timNhanVien(vector<PhongBan> PB, vector<NhanVien> NV){
    int id;
    cout << "Nhap Ma Nhan Vien Can Tim: "; cin >> id;
    for(NhanVien tempNV : NV){
        if(tempNV.getMaNV() == id){
           tempNV.output(PB);
            }
        }
    }

int PhongBan :: maPhongBanCounter = 99;
int NhanVien :: maNVCounter = 999;
int main(){
    vector<PhongBan> PB;
    vector<NhanVien> NV;
    int pb, nv;
    cout << "Nhap So Phong Ban: "; cin >> pb;
    for(int i = 0; i < pb; i++){
        PhongBan temp("name","describe",0);
        temp.input();
        PB.push_back(temp);
    }
    cout << "Nhap So Nhan Vien: "; cin >> nv;
    for(int j = 0; j < nv; j++){
        NhanVien temp("name",0,0,0);
        temp.input();
        NV.push_back(temp);
    }
    cout <<"\nDanh Sach Nhan Vien: \n";
    for(NhanVien temp: NV){
        temp.output();
        cout << endl;
    }
    cout << endl;
    timNhanVien(PB, NV);
    return 0;
}
