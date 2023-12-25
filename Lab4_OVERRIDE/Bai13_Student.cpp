#include<iostream>
#include<vector>
using namespace std;
class SinhVien{
private:
    static int maSVCounter;
    int maSV;
    string tenSV;
    string lopSV;
public:
    SinhVien(){
        maSV = ++maSVCounter;
    }
    void input(){
        cout << "Nhap Ten Sinh Vien: "; cin >> tenSV;
        cout << "Nhap Lop: "; cin >> lopSV;
    }
    void output(){
        cout << "MaSV: " << maSV << "\t" << "TenSV: " << tenSV << "\t" << "Lop: " << lopSV << endl;
    }
    int getMaSV(){
        return maSV;
    }
    friend class BangDiem;
};
class MonHoc{
private:
    static int maMHCounter;
    int maMH;
    int soDVHT;  // So Don Vi Hoc Thuat
    string tenMH;
    string loaiMon;
public:
    MonHoc(){
        maMH = ++maMHCounter;
    }
    void input(){
        cout << "Nhap Ten Mon Hoc: "; cin >> tenMH;
        cout << "Nhap Loai Mon Hoc: "; cin >> loaiMon;
        cout << "Nhap so DVHT: "; cin >> soDVHT;
    }
    void output(){
        cout << "Ma MH: " << maMH << "\t" << "Ten: " << tenMH << "\t" << "Loai: " << loaiMon << "\t" << "So DVHT: " << soDVHT << endl;
    }
    friend class BangDiem;
};
class BangDiem{
private:
    int maSV;
    int maMH;
    double diemMH;
public:
    BangDiem(){};
    int getMaSV(){
        return maSV;
    }
    void input(){
        int idSV;
        cout << "Nhap Ma SV: "; cin >> idSV;
        if(idSV >= 10000){
            maSV = idSV;
        }
        cout << "Nhap Ma MH: "; cin >> maMH;
        double diem;
        cout << "Nhap Diem MH: "; cin >> diem;
        while(true){
            if(diem >= 0 && diem <= 10){
                diemMH = diem;
                break;
            } else {
                cout << "Nhap Lai. ( 0 - 10 )";
            }
        }
    }
    void searchScore(vector<MonHoc> Subject, int idSV){
            if(idSV == maSV){
                for(int j = 0; j < Subject.size(); j++){
                    if(Subject[j].maMH == maMH){
                        cout << "Ten MH: " << Subject[j].tenMH <<"\t"<<"Diem: " << diemMH << endl;
                    }
                }
            }
    }
};
int SinhVien::maSVCounter = 9999;
int MonHoc::maMHCounter = 99;
int main(){
    vector<MonHoc> Subject;
    vector<SinhVien> Student;
    vector<BangDiem> Score;
    int sb, st;
    cout << "Nhap So Mon Hoc: "; cin >> sb;
    for(int i = 0; i < sb; i++){
        MonHoc temp;
        temp.input();
        Subject.push_back(temp);
    }
    cout << "Nhap So Sinh Vien: "; cin >> st;
    for(int i = 0; i < st; i++){
        SinhVien temp;
        temp.input();
        Student.push_back(temp);
    }
    for(int i = 0; i < st; i++){
        cout << "\nNhap Diem Sinh Vien Thu " << i + 1 << ": \n";
        int count = 0;
        while(count < Subject.size()){   // Moi Sinh vien Co Toi Da Dau Diem Ung Voi Danh Sach Mon Hoc
            BangDiem temp;
            temp.input();
            if(temp.getMaSV() < 10000){ // Dung Viec Nhap Diem Khi MaSV < 10000;
                break;
            }
            Score.push_back(temp);
            count++;
        }
    }
    int idSV;
    cout << "Nhap Ma SV Muon Xem Diem: "; cin >> idSV;
    for(int i = 0; i < Student.size(); i++){
        if(idSV == Student[i].getMaSV()){
            for(int j = 0; j < Score.size(); j++){
                Score[j].searchScore(Subject, idSV);
            }
        }
    }
    return 0;
}
