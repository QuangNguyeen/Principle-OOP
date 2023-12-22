#include<iostream>
#include "Pixel.h"
using namespace std;
int main(){
    int n;
    cout << "Nhap so pixel: ";
    cin >> n;
    Pixel pixel[n];
    for(int i = 0; i < n; i++){
        cin >> pixel[i];
    }
    cout << "Cac pixel nam tren duong cheo chinh va co mau Xanh la: "<< endl;
    for(int i = 0; i < n; i++){
        if(pixel[i].KiemTra()){
            cout << pixel[i];
        }
    }
    return 0;
}
