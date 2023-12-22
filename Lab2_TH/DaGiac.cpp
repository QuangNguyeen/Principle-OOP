//
// Created by macbook on 05/12/2023.
//

#include "DaGiac.h"
#include <iostream>
using namespace std;
int main(){
        int n;
        cout << "Nhap N: ";
        cin >> n;
        DaGiac a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cout << a[i];
        }
        return 0;
    }
