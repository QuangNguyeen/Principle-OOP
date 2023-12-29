#include<iostream>
#include<cmath>
using namespace std;
class Circle{
private:
    double radius;
public:
    void input(){
        cout << "Enter value of Radius: "; cin >> radius;
    }
    double Perimeter(){
        return radius*2*M_PI;
    }
    double Area(){
        return pow(radius,2) * M_PI;
    }
    void output(){
        cout << "Radius: " << radius << endl;
        cout << "Perimeter: " << Perimeter() << endl;
        cout << "Area: " << Area() << endl;
    }
};
int main(){
    Circle circle;
    circle.input();
    circle.output();
    return 0;
}