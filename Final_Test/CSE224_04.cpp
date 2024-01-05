#include <iostream>
using namespace std;

class Vehicles {
private:
    int standardSpeed;

public:
    // Constructor
    Vehicles() {}
    Vehicles(int tocdo) : standardSpeed(tocdo) {}

    int getStandardSpeed() const {
        return standardSpeed;
    }

    virtual void input() {
        cout << "Enter value of standard Speed: ";
        cin >> standardSpeed;
    }

    virtual void output() const {
        cout << "Standard Speed: " << standardSpeed;
    }

    virtual double maxSpeed() const = 0;
};

class Ferrari : public Vehicles {
private:
    string Color;
    double speedCoefficient; // He So Toc Do

public:
    Ferrari() {}
    Ferrari(int tocdo, string mau, double heso) : Vehicles(tocdo), Color(mau), speedCoefficient(heso) {}

    double maxSpeed() const override {
        return (getStandardSpeed() * speedCoefficient);
    }

    void input() override {
        Vehicles::input();
        cout << "Enter Color: ";
        cin >> Color;
        cout << "Enter Speed Coefficient: ";
        cin >> speedCoefficient;
    }

    void output() const override {
        Vehicles::output();
        cout << "\nColor: " << Color << endl;
        cout << "Speed Coefficient: " << speedCoefficient;
    }

    bool operator>(const Ferrari& other) const {
        return (this->maxSpeed() > other.maxSpeed());
    }
};

int main() {
    int n;
    Ferrari maxFerrari;
    cout << "Enter number of Ferraris: ";
    cin >> n;

    Ferrari** listCar = new Ferrari*[n];

    for (int i = 0; i < n; i++) {
        listCar[i] = new Ferrari;
        listCar[i]->input();
    }

    cout << "\nList Car Ferraris: \n";
    for (int i = 0; i < n; i++) {
        listCar[i]->output();
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        if (*listCar[i] > maxFerrari) {
            maxFerrari = *listCar[i];
        }
    }

    cout << "\nMax Ferrari: \n";
    maxFerrari.output();

    // Clean up allocated memory
    for (int i = 0; i < n; i++) {
        delete listCar[i];
    }
    delete[] listCar;

    return 0;
}
