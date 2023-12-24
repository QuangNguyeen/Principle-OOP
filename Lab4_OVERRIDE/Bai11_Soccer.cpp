#include<iostream>
#include<vector>
using namespace  std;
class ViTri{
private:
    static int maVitriCounter;
    int maVitri;
    string tenVitri;
    double mucThuong;
public:
    // Constructor
    ViTri(){
        maVitri = ++ maVitriCounter;
    }
    void input(){
        cout << "Nhap Ten Vi Tri Thi Dau: "; cin >> tenVitri;
        cout << "Nhap Muc Thuong Nhan Duoc: "; cin >> mucThuong;
    }
    void output(){
        cout << "Ma Vi Tri: " << maVitri << "\t" << "Ten Vi Tri: " << tenVitri << "\t" << "Muc Thuong: " << mucThuong << endl;
    }
    friend class CauThu;
};
class Nguoi{
protected:
    string hoTen;
    string diaChi;
    string SDT;
public:
    virtual void input(){};
    virtual void output(){};
};
class CauThu : public Nguoi{
private:
    static int maCauThuCounter;
    int maCauThu;
    double mucLuong;
    int maViTri;
public:
    // Constructor
    CauThu(){
        maCauThu  = ++maCauThuCounter;
    }
    int getMaCauThu() const {
        return maCauThu;
    }
    void input(){
        cout << "Nhap Ho Ten: "; cin >> hoTen;
        cout << "Nhap Dia Chi: "; cin >> diaChi;
        cout << "Nhap SDT: "; cin >> SDT;
        cout << "Nhap Ma Vi Tri Thi Dau: "; cin >> maViTri;
        cout << "Nhap Muc Luong: "; cin >> mucLuong;
    }
    void output(){
        cout << "Ma: " << maCauThu << "\t"<< "Ten: " << hoTen << "\t" << "Dia Chi: " << diaChi << "\t" << "SDT: " << SDT << endl;
        cout << "Ma Vi Tri: " << maViTri << "\t" << "Muc luong: " << mucLuong << endl;
    }
    void output(vector<ViTri> Position) const{
        bool checkExist= false;
        int size = Position.size();
        for(int i = 0; i < size; i++){
            if(this->maViTri == Position[i].maVitri){
                checkExist = true;
                cout << "Muc Thuong: " << Position[i].mucThuong;
            }
        }
        if(checkExist){
            cout << "Khong co thuong.";
        }
    }
};
void NhapThongTin(vector<ViTri> &Position, int pt){
    for(int i = 0; i < pt; i++){
        ViTri temp;
        temp.input();
        Position.push_back(temp);
    }
}
void NhapThongTin(vector<CauThu> &Player, int pl){
    for(int i = 0; i < pl; i++){
        CauThu temp;
        temp.input();
        Player.push_back(temp);
    }
}
void XuatThongTin(vector<ViTri> Position){
    int size = Position.size();
    for(int i = 0; i < size; i++){
        Position[i].output();
        cout << endl;
    }
};
void XuatThongTin(vector<CauThu> Player){
    int size = Player.size();
    cout << "\nDanh Sach Cac Player\n";
    for(int i = 0; i < size; i++){
        Player[i].output();
        cout << endl;
    }
};
void TimMucThuong(vector<ViTri> Position, vector<CauThu> Player, int id){
    int size = Player.size();
    for(int i = 0; i < size; i++){
        if(id == Player[i].getMaCauThu()){
            Player[i].output(Position);
        }
    }
};
int ViTri ::maVitriCounter = 99;
int CauThu ::maCauThuCounter = 99;
int main(){
    vector<ViTri> Position;
    vector<CauThu> Player;
    int pt, pl, id;
    cout << "Nhap So Vi Tri Thi Dau: "; cin >> pt;
    NhapThongTin(Position, pt);
    cout << endl;
    XuatThongTin(Position);
    cout << endl;
    cout << "Nhap So Cau Thu Thi Dau: "; cin >> pl;
    NhapThongTin(Player, pl);
    cout << endl;
    XuatThongTin(Player);
    cout << "Nhap ID Tin Cau Thu Muon Xem Muc Thuong: ";
    cin >> id;
    TimMucThuong(Position, Player, id);
    return 0;
}