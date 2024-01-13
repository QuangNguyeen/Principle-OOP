#include<iostream>
#include<vector>
using namespace std;
class MonHoc{
private:
    string MaMH, TenMH;
    int SoTinChi;
public:
    // Constructor
    MonHoc(){};
    MonHoc(string id, string name, int tc){
        MaMH = id;
        TenMH = name;
        SoTinChi = tc;
    }
    // getter
    string getID(){
        return MaMH;
    }
    string getName(){
        return TenMH;
    }
    int getSoTinChi(){
        return  SoTinChi;
    }
    // setter
    void setID(string id){
        MaMH = id;
    }
    void setName(string name){
        TenMH = name;
    }
    void setTinChi(int tc){
        SoTinChi = tc;
    }
    virtual void input(){
        cout << "Nhap Ma Mon Hoc: "; cin >> MaMH;
        cout << "Nhap Ten Mon Hoc: "; cin >> TenMH;
        cout << "Nhap So Tin Chi: "; cin >> SoTinChi;
    }
    virtual void output(){
        cout << "ID: " << MaMH << "\t" << "Name: " << TenMH << "\t" << "SoTC: " << SoTinChi;
    }
};
class ToanHoc : public MonHoc{
private:
    string KieuMonHoc;
public:
    // Constructor
    ToanHoc(){};
    ToanHoc(string id, string name, int tc, string type) : MonHoc(id, name, tc){
        KieuMonHoc = type;
    }
    // getter
    string getType(){
        return KieuMonHoc;
    }
    // setter
    void setType(string type){
        KieuMonHoc = type;
    }
    void input(){
        MonHoc::input();
        cout << "Nhap Kieu Mon Hoc: "; cin >> KieuMonHoc;
    }
    void output(){
        MonHoc::output();
        cout << "Type: " << KieuMonHoc;
    }
    // Nap trong toan tu !=
    bool operator !=(MonHoc other){
        return (this->getID() == other.getID());
    }

};
int main(){
    vector<ToanHoc> listMath;
    int n;
    cout << "Nhap So Mon Thuoc Vien Toan: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        ToanHoc temp;
        temp.input();
        listMath.push_back(temp);
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        listMath[i].output();
        cout << endl;
    }
    ToanHoc newMath;
    newMath.input(); // Nhap Thon Tin
    bool checkExist = false;
    for(int i = 0; i < n; i++){
        if(!(newMath != listMath[i])){
            checkExist = true;
            break;
        }
    }
    if(checkExist){
        cout << "Mon Hoc Ton Tai";
    } else {
        cout << "Mon KHONG ton tai";
    }
//    MonHoc *listMath2[n];
//    for(int i = 0; i < n; i++){
//        listMath2[i] = new ToanHoc;
//        listMath2[i]->input();
//    }
    return 0;
}