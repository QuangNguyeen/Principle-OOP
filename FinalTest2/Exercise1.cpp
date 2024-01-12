#include<iostream>
#include<vector>
using namespace std;
class BanDoc{
private:
    static int maBanDocCounter;
    int maBanDoc;
    string hoTen, diaChi, SDT, loaiBanDoc;
public:
    // Constructor
    BanDoc(){
        maBanDoc = ++maBanDocCounter;
    };
    int getID(){
        return maBanDoc;
    }
    void input(){
        cout << "Nhap Ho Ten: "; cin >> hoTen;
        cout << "Nhap Dia Chi: "; cin >> diaChi;
        cout << "Nhap SDT: "; cin >> SDT;
        cout << "Nhap Loai Ban Doc: "; cin >> loaiBanDoc;
    }
    void output(){
        cout << "ID: " << maBanDoc << "\t" <<
        "Name: " << hoTen << "\t" << "Address: " << diaChi << "\t" << "Phone: " << SDT <<"\t" <<"Type: " << loaiBanDoc;
    }
};
class Sach{
private:
    static int maSachCounter;
    int maSach;
    string tenSach, tacGia, chuyenNganh;
    int namXuatBan;
public:
    // Constructor
    Sach(){
        maSach = ++maSachCounter;
    }
    // getter
    int getID() const {
        return maSach;
    }
    void input(){
        cout << "Nhap Ten Sach: "; cin >> tenSach;
        cout << "Nhap Tac Gia: "; cin >> tacGia;
        cout << "Nhap Chuyen Nganh: "; cin >> chuyenNganh;
        cout << "Nhap Nam Xuat Ban: "; cin >> namXuatBan;
    }
    void output(){
        cout << "BookID: " << maSach << "\t"
        << "Name: " << tenSach << "\t" << "Author: " << tacGia << "\t" << "Major: "
        << chuyenNganh << "\t" << "Year: " << namXuatBan;
    }
};
class QLBanDoc {
private:
    BanDoc reader;
    vector<Sach> listOfBorrowedBook;
public:
    void setReader(BanDoc bandoc){
        this->reader = bandoc;
    }
    int getNumberBorrowedBook(){
        return listOfBorrowedBook.size();
    }
    void inputInforBook(vector<Sach> listBook, int n){
        for(int i = 0; i < n; i++){
            int idBook;
            bool checkExist = false;
            cout << "Nhap Ma Sach Muon Muon: "; cin >> idBook;
            if(idBook >= 10000){
                for(int j = 0; j < listBook.size(); j++){
                    int countBook = 0;
                    if(idBook == listBook[j].getID()){
                        checkExist = true;
                        for(int k = 0; k < listOfBorrowedBook.size(); k++){
                            if(idBook == listOfBorrowedBook[k].getID()){
                                countBook++;
                            }
                        }
                        if(countBook <3){
                            Sach temp = listBook[j];
                            listOfBorrowedBook.push_back(temp);
                        } else{
                            cout << "Vuot qua 3 quyen / dau sach. Nhap Ma Sach Khac. ";
                            --i;
                        }
                    }
                }
            } else {
                cout << "Ma Sach Khong Hop Le. ";
                --i;
            }
        if(!checkExist){
            cout << "Ma Sach Khong Hop Le. ";
            --i;
        }
        }
    }
    int theFrequency(Sach book){
        int count = 0;
        for(int i = 0; i < listOfBorrowedBook.size(); i++){
            if(book.getID() == listOfBorrowedBook[i].getID()){
                count++;
            }
        }
        return count;
    }
    void output(){
        reader.output();
        cout << endl;
        for(int i = 0; i < listOfBorrowedBook.size(); i++){
            bool checkExist = false;
            for(int j = 0; j < i; ++j){
                if(listOfBorrowedBook[i].getID() == listOfBorrowedBook[j].getID()){
                    checkExist = true;
                    break;
                }
            }
            if(!checkExist){
                listOfBorrowedBook[i].output();
                cout <<"\tQuanity: " << theFrequency(listOfBorrowedBook[i]) << endl;
            }
        }
    }
};
// Selection Sort
void sortListManagement(vector<QLBanDoc> &listManagemnet){
    int i, j , max, size = listManagemnet.size();
    for(i = 0; i < size - 1; i++ ){
        max = i;
        for(j = i + 1; j < size; j++){
            if(listManagemnet[j].getNumberBorrowedBook() > listManagemnet[max].getNumberBorrowedBook()){
                max = j;
            }
        }
        if(max != i){
            QLBanDoc temp = listManagemnet[i];
            listManagemnet[i] = listManagemnet[max];
            listManagemnet[max] = temp;
        }
    }
}
int BanDoc::maBanDocCounter = 9999;
int Sach::maSachCounter = 9999;
int main(){
    vector<Sach> listBook;
    vector<BanDoc> listReader;
    vector<QLBanDoc> listManagement;
    int numberBook;
    cout << "Nhap So Dau Sach Hien Co: "; cin >> numberBook;
    for(int i = 0; i < numberBook; i++){
        Sach temp;
        temp.input();
        listBook.push_back(temp);
    }
    cout << "\nThong Tin Cac Dau Sach: \n";
    for(int i = 0; i < numberBook; i++){
        listBook[i].output();
        cout << endl;
    }
    cout << endl;
    int numberReader;
    cout << "Nhap So Ban Doc: "; cin >> numberReader;
    for(int i = 0; i < numberReader; i++){
        BanDoc temp;
        temp.input();
        listReader.push_back(temp);
    }
    cout << "\nThong Tin Ban Doc: \n";
    for(int i = 0; i < numberReader; i++){
        listReader[i].output();
        cout << endl;
    }
    for(int i = 0; i < listReader.size(); i++){
        int numberBorrowedBook;
        QLBanDoc temp;
        temp.setReader(listReader[i]);
        cout << "Ban Doc Ma: " << listReader[i].getID();
        cout << "\nNhap So Sach Muon Muon: "; cin >> numberBorrowedBook;
        temp.inputInforBook(listBook, numberBorrowedBook);
        listManagement.push_back(temp);
    }
    cout << "\nThong Tin Quan Ly: \n";
    // After sort by the number of borrowed book
    sortListManagement(listManagement);
    for(int i = 0; i < listReader.size(); i++){
        listManagement[i].output();
        cout << "\n";
    }
    return 0;
}
