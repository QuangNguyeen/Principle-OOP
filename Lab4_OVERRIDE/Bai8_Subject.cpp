#include<iostream>
#include<vector>
using namespace std;
class MonHoc{
private:
    static int maMonHocCounter;
    int maMonHoc;
    string tenMonHoc;
    int tongSoTiet;
    string loaiMonHoc;
public:
    MonHoc(string name, int soTiet, string type){
        maMonHoc = ++ maMonHocCounter;
        tenMonHoc = name;
        tongSoTiet = soTiet;
        loaiMonHoc = type;
    }
    void inputMonHoc(){
        cout << "Nhap Ten Mon Hoc: ";               cin >> tenMonHoc;
        cout << "Nhap Tong So Tiet cua Mon Hoc: ";  cin >> tongSoTiet;
        cout << "Nhap Loai Mon Hoc: ";              cin >> loaiMonHoc;
    }
    void outputMonHoc(){
        cout << "Ten: " << tenMonHoc << "\t" << "So Tiet: " << tongSoTiet << "\t" << "Loai: " << loaiMonHoc  << endl;
    }
};
class Nguoi{
protected:
    string hoTen;
    string diaChi;
    string SDT;
};
class SinhVien : public Nguoi{
private:
    static int maSVCounter;
    int maSV;
    int soMonHoc;
    vector<int> listMonHoc;
public:
    SinhVien(string name, string address, string phone, int soMon){
        hoTen = name;
        diaChi = address;
        SDT = phone;
        maSV = ++ maSVCounter;
        soMonHoc = soMon;
    }
    char getFirstCharInHoTen(){
        return hoTen[0];
    }
    void inputSinhVien(){
        cout << "Nhap Ten SV: "; cin >> hoTen;
        cout << "Nhap Dia Chi SV: "; cin >> diaChi;
        cout << "Nhap SDT: "; cin >> SDT;
        cout << "Nhap So Mon Hoc : ";  cin >> soMonHoc;
        cout << "Nhap Danh Sach Ma Mon Hoc: \n";
        int i = 0;
        do{
            int n;
            cout << "Ma Mon Hoc Thu " << i + 1 << ": "; cin >> n;
            if(n >=100){
                listMonHoc.push_back(n);
                i++;
            } else {
                cout << "Ma Mon Hoc Khong Hop Le !";
                i--;
            }
        } while(i < soMonHoc);
    }
    void outputSinhVien(){
        cout << "Ten: " << hoTen << "\t" << "Dia Chi: " << diaChi << "\t" << "SDT: " << SDT;
        cout << "\tMaSV: " << maSV << "\t" << "So Mon Hoc: " << soMonHoc;
        cout << "\nDanh Sach Ma Mon Hoc: \n";
        for(int i : listMonHoc){
            cout << i << endl;
        }
    }
};
// Dung Sap Xep Chon: Selection Sort
void sortListSinhVien(vector<SinhVien> &sv){
    int i, j , min;
    int size = sv.size();
    for(i = 0; i < size - 1; i++){
        min = i;
        for(j = i+1; j < size; j++){
            if(sv[j].getFirstCharInHoTen() < sv[min].getFirstCharInHoTen() ){
                min = j;
            }
        }
        if(min != i){
            SinhVien temp = sv[i];
            sv[i] = sv[min];
            sv[min] = temp;
        }
    }
}
int MonHoc :: maMonHocCounter = 99;
int SinhVien :: maSVCounter = 9999;
int main(){
    int n;
    vector<MonHoc> listSubject;
    vector<SinhVien> listStudent;
    cout << "Tong So Mon Hoc Co The Dang Ky: "; cin >> n;
    for(int i = 0; i < n; i++){
        MonHoc temp("name", 0,"type");
        temp.inputMonHoc();
        listSubject.push_back(temp);
    }
    int m;
    cout << "Tong So Sinh Vien: "; cin >> m;
    for(int i = 0; i < m; i++){
        SinhVien temp("name","address","phone", 0);
        temp.inputSinhVien();
        listStudent.push_back(temp);
    }
    sortListSinhVien(listStudent);
    for(SinhVien temp : listStudent){
        temp.outputSinhVien();
    }
    return 0;
}
