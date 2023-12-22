//
// Created by macbook on 05/12/2023.
//
#include<iostream>
#include<vector>
#include "VanDongVien.h"
using namespace std;
void input(vector<VanDongVien> &athlete, int n){
    for(int i = 0; i < n; i++){
        cin >> athlete[i];
    }
}
void output(vector<VanDongVien> athlele){
    int size = athlele.size();
    for(int i = 0; i < size; i++){
        cout << athlele[i];
    }
}
int main(){
    VanDongVien p = VanDongVien("Quang", 19,"Cau Long",60,1.75 );
    int n;
    cout << "Nhap N: ";
    cin >> n;
    vector<VanDongVien> athlete(n);
    cout << "Enter information of athlete: " << endl;
    input(athlete,n);
    int min_index;
    for(int i = 0; i < n - 1; i++){
        min_index = i;
        for(int j = i + 1; j < n; j++){
            if(!athlete[j].operator>(athlete[min_index])){
                min_index = j;
            }
        }
        swap(athlete[min_index], athlete[i]);
    }
    cout << "After sort: " << endl;
    output(athlete);
    return 0;
}
