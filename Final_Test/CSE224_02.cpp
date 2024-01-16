#include<iostream>
using namespace std;

class PhuongTien {
protected:
    float Tocdo;

public:
    PhuongTien() {};
    PhuongTien(float speed) : Tocdo(speed) {}
    virtual float maxSpeed() const = 0;
    bool operator>( const PhuongTien& other) {
        return this->maxSpeed() > other.maxSpeed();
    }
    virtual void input() = 0;
    virtual void output() const = 0;
    virtual ~PhuongTien() {}
};

class Oto : public PhuongTien {
private:
    string mauSac;
    float heSoTocDo;

public:
    Oto() {};
    Oto(float speed, string color, float heso) : PhuongTien(speed) {
        mauSac = color;
        heSoTocDo = heso;
    }
    float maxSpeed() const  {
        return Tocdo * heSoTocDo;
    }
    void input()  {
        cout << "Nhap Toc Do Tieu Chuan: "; cin >> Tocdo;
        cout << "Nhap Mau Sac: "; cin >> mauSac;
        cout << "Nhap He So Toc Do: "; cin >> heSoTocDo;
    }
    void output() const  {
        cout << "Toc Do Tieu Chuan: " << Tocdo << "\t" << "Mau Sac: " << mauSac << "\t" << "HeSoTocDo: " << heSoTocDo
             << "\t" << "Toc Do Toi Da: " << maxSpeed() << endl;
    }
};

class XeMay : public PhuongTien {
private:
    int namSX;

public:
    XeMay() {};
    XeMay(float speed, int year) : PhuongTien(speed) {
        namSX = year;
    }
    float maxSpeed() const  {
        return 0.5 * Tocdo;
    }
    void input()  {
        cout << "Nhap Toc Do Tieu Chuan: "; cin >> Tocdo;
        cout << "Nhap Nam San Xuat: "; cin >> namSX;
    }
    void output() const {
        cout << "TocDoTieuChuan: " << Tocdo << "\t" << "TocDoToiDa: " << maxSpeed() << "\t" << "NamSX: " << namSX << endl;
    }
};

int main() {
    int n;
    do {
        cout << "Nhap So Phuong Tien: "; cin >> n;
    } while (n <= 0 || n >= 10);

    PhuongTien* listVehicles[n];

    for (int i = 0; i < n; i++) {
        int choice;
        cout << "Chon Loai Phuong Tien (0 la XeMay, 1 la Oto): "; cin >> choice;
        switch (choice) {
            case 0:
                listVehicles[i] = new XeMay;
                listVehicles[i]->input();
                break;
            case 1:
                listVehicles[i] = new Oto;
                listVehicles[i]->input();
                break;
            default:
                cout << "Khong Co Loai Xe Do. ";
                break;
        }
    }

    for (int i = 0; i < n; i++) {
        listVehicles[i]->output();
    }
    PhuongTien *min = listVehicles[0];

    for(int i = 0; i < n; i++){
        if(min->maxSpeed() > listVehicles[i]->maxSpeed()){
            min = listVehicles[i];
        }
    }
    cout << "Min: ";
    min->output();
    // Don't forget to deallocate memory
    for (int i = 0; i < n; i++) {
        delete listVehicles[i];
    }

    return 0;
}
