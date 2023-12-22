#include<iostream>
#include "DanhSachMuaHang.h"
#include<vector>
using namespace std;
int main() {
    std::vector<MatHang> Hang;
    std::vector<KhachHang> KH;
    std::vector<DanhSachMuaHang> List;
    int i;

    // Input product data
    std::cout << "Nhap Danh Sach Mat Hang: ";
    while (true) {
        MatHang temp;
        std::cin >> temp;
        if (temp.getMaH() == 0) break;  // Nhap MaH = 0 de thoat
        Hang.push_back(temp);
    }

    // Display product data
    std::cout << "Danh Sach Cac Mat Hang Da Co: \n";
    std::cout << "MaH" << "\t" << "TenH" << "\t" << "NhomH" << "\t" << "Gia" << std::endl;
    for (i = 0; i < Hang.size(); i++) {
        std::cout << Hang[i];
    }

    // Input customer data
    std::cout << "\nNhap Danh Sach Khach Hang: ";
    while (true) {
        KhachHang temp;
        std::cin >> temp;
        if (temp.getMaKH() == 0) break;  // Nhap MaKH = 0 de thoat
        KH.push_back(temp);
    }

    // Display customer data
    for (i = 0; i < KH.size(); i++) {
        std::cout << KH[i];
    }
    // Create a shopping list for each customer
    for (i = 0; i < KH.size(); i++) {
        DanhSachMuaHang temp;
        temp.setKhachHang(KH[i]);
        int CodeHang;
        while(true){
            std::cout << "Nhap Ma Hang Can Mua: (Nhap 0 de thoat ): \n";
            std::cin >> CodeHang;
            if(CodeHang != 0){
                for (int j = 0; j < Hang.size(); j++) {
                    if (CodeHang == Hang[j].getMaH()) {
                        temp.setMatHang(Hang[j], j);
                    }
                }
            } else break;
        }
        List.push_back(temp);
    }

    // Display shopping lists
    for (i = 0; i < List.size(); i++) {
        std::cout << List[i];
    }

    return 0;
}
