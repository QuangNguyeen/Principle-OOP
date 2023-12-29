#include<iostream>
using namespace std;

class Vector{
private:
    float * v;
    int n;
public:
    Vector(){
        cout << "Enter value of n: "; cin >> n;
        v = new float[n];
        for(int i = 0; i < n; i++){
            cout << "Dimension " << i + 1 << ": ";
            cin >> v[i];
        }
    }
    Vector(int n){
        this->n = n;
        v = new float[n];
        for(int i = 0; i < n; i++){
            cout << "Dimension " << i + 1 << ": ";
            cin >> v[i];
        }
    }
    Vector(int n, float vector[]){
        this->n = n;
        v = new float[n];
        for(int i = 0; i < n; i++){
            v[i] = vector[i];
        }
    }
    Vector(Vector const &p){
        n = p.n;
        v = p.v;
    }
    void output(){
        cout << "The number of dimension: " << n << endl;
        for(int i = 0; i < n; i++){
            cout << "Dimension " << i + 1 << ": " << v[i] << endl;
        }
    }
    void DesVector(){
        delete v;
    }
};
int main(){
    cout << "Vector 1: \n";
    Vector vector1;
    vector1.output();
    vector1.DesVector();
    cout << "\nVector 2: \n";
    Vector vector2(2);
    vector2.output();
    float a[] = {6,7};
    cout << "\nVector 3: \n";
    Vector vector3(2, a);
    vector3.output();
    cout << "\nVector 4: \n";
    Vector vector4(vector3);
    vector4.output();
    return 0;
}
