#include <iostream>
#include <string>
#include<vector>
using namespace std;

class Sach {
private:
    static int maSachCounter;
    int maSach;
    string tenSach;
    string tacGia;
    string chuyenNganh;
    int namXuatBan;
public:
    Sach(string name, string author, string major, int namXB) {
        this->maSach = ++maSachCounter;
        this->tenSach = name;
        this->tacGia = author;
        this->chuyenNganh = major;
        this->namXuatBan = namXB;
    }
    int getMaSach() const {
        return maSach;
    }
    virtual void input(){
        cout << "Nhap Ten Sach: "; cin >>  tenSach;
        cout << "Nhap Tac Gia cua Sach: "; cin >> tacGia;
        cout << "Nhap Chuyen Nganh cua Sach: "; cin >> chuyenNganh;
        cout << "Nhap Nam Xuan Ban: "; cin >> namXuatBan;
    }
    virtual void output() const {
        cout << "Ma sach: " << maSach << endl;
        cout << "Ten sach: " << tenSach << endl;
        cout << "Tac gia: " << tacGia << endl;
        cout << "Chuyen nganh: " << chuyenNganh << endl;
        cout << "Nam xuat ban: " << namXuatBan << endl;
    }
};
class Nguoi{
protected:
    string hoTen;
    string diaChi;
    string SDT;
};
class Bandoc : public Nguoi{
private:
    static int maBanDocCounter;
    int maBanDoc;
    int soSachMuon;
    string loaiBanDoc;
    vector<int> danhSachMaSach;
public:
    Bandoc(string ten, string diaChi, string SDT, int soSachMuon, string loai){
        this->maBanDoc = ++maBanDocCounter;
        this->hoTen = ten;
        this->diaChi = diaChi;
        this->SDT = SDT;
        this->soSachMuon = soSachMuon;
        this->loaiBanDoc = loai;
    }
    int getIdBanDoc(){
        return maBanDoc;
    }
    vector<int> getListSach(){
        return danhSachMaSach;
    }
    void input(){
        cout << "Nhap Ho Ten: "; cin >> hoTen;
        cout << "Nhap Dia Chi: "; cin >> diaChi;
        cout << "Nhap SDT: ";     cin >> SDT;
        cout << "Nhap So Sach Muon: "; cin >> soSachMuon;
        cout << "Nhap Loai Ban Doc: "; cin >> loaiBanDoc;
        for(int i = 0; i < soSachMuon; i++){
            int n;
            cout << "Nhap Ma Sach "; cin >> n;
            if(n>=10000){
                danhSachMaSach.push_back(n);
            } else {
                cout << "Ma sach khong hop le";
            }
        }
    }
    void output(){
        cout << "Ho Ten: " << hoTen << "\t\t" << "Dia Chi: " << diaChi << "\t" << "SDT: " << SDT << endl;
        cout << "Ma Ban Doc: "<< maBanDoc << "\t" << "Loai: " << loaiBanDoc << "\t" << "So Sach Muon: " << soSachMuon << endl;
        cout << "Danh sach Ma sach Muon: \n";
        for(int i = 0; i < danhSachMaSach.size(); i++){
            cout << danhSachMaSach[i] << endl;
        }
    }
};
// Khởi tạo biến tăng tự động
int Sach::maSachCounter = 9999;  // Bắt đầu từ 10000
int Bandoc::maBanDocCounter = 9999;
int main() {
    // Nhap Danh Sach Cac Cuon Sach Hien Co
    int numberBook;
    cout << "Nhap Tong So Sach Hien Co: ";
    cin  >> numberBook;
    vector<Sach> listBook;
    vector<Bandoc> listBanDoc;
    for(int i = 0; i < numberBook; i++){
        Sach temp("name","author", "major", 0);
        temp.input();
        listBook.push_back(temp);
    }

    // Nhap Danh Sach Ban Doc
    int numberBanDoc;
    cout << "\nNhap So Luong Ban Doc: ";
    cin >> numberBanDoc;
    for(int i = 0; i < numberBanDoc; i++){
        Bandoc temp("name", "address", "phone", 0, "type");
        temp.input();
        listBanDoc.push_back(temp);
    }

    // In ra Danh Sach Ban Doc
    for(int i = 0; i < numberBanDoc; i++){
        listBanDoc[i].output();
    }

    // Tim Kiem Ban Doc
    int idBanDoc;
    cout << "\nNhap Ma Ban Doc Can Tim Kiem: "; cin >> idBanDoc;
    for(Bandoc temp : listBanDoc){
        if(temp.getIdBanDoc() == idBanDoc){
            temp.output();
            cout << "Danh Sach Cac Cuon Sach Da Muon: \n";
            for(Sach sach : listBook){
                for(int i = 0; i < temp.getListSach().size(); i++){
                    if(sach.getMaSach() == temp.getListSach()[i]){
                        sach.output();
                        cout << endl;
                    }
                }
            }
        }
    }
    return 0;
}

