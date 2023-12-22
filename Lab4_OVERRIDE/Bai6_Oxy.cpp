#include<iostream>
using namespace std;
class Oxy{
protected:
    float x, y;
public:
    Oxy(){};
    ~Oxy(){};
    friend istream &operator>>(istream &in, Oxy& point2D);  // Friend Function
    friend ostream &operator<<(ostream &out, Oxy point2D);  // Friend Function
    friend Oxy Midpoint(Oxy A, Oxy B);
};
istream &operator>>(istream &in, Oxy &point2D){
    cout << "Enter value of x: "; in >> point2D.x;
    cout << "Enter value of y: "; in >>point2D.y;
    return in;
}
ostream &operator<<(ostream &out, Oxy oxy){
    cout << "x = " << oxy.x << "\t" << "y = " << oxy.y << endl;
    return out;
}
Oxy Midpoint(Oxy A, Oxy B){
    Oxy C;
    C.x = ( A.x + B.x) / 2;
    C.y =  (A.y + B.y) / 2;
    return C;
}
class Oxyz : public  Oxy{
private:
    float z;
public:
    Oxyz(){};
    Oxyz(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }; // Constructor
    ~Oxyz(){}; // Destructor
    friend istream &operator>>(istream &in, Oxyz &point);
    friend ostream &operator<<(ostream &out, Oxyz point);
    friend Oxyz Midpoint(Oxyz A, Oxyz B);
    float getX(){
        return x;
    }
    float getY(){
        return y;
    }
    float getZ(){
        return z;
    }
};
istream &operator>>(istream &in, Oxyz &point){
    cout << "Enter value of x: "; in >> point.x;
    cout << "Enter value of y: "; in >> point.y;
    cout << "Enter value of z: "; in >> point.z;
    return in;
}
ostream &operator<<(ostream &out, Oxyz point){
    cout << "x = " << point.x << "\t" << "y = " << point.y << "\t" <<"z = "<< point.z << endl;
    return out;
}
Oxyz Midpoint(Oxyz A, Oxyz B){
    Oxyz G;
    G.x = (A.x + B.x ) / 2;
    G.y = (A.y + B.y ) / 2;
    G.z = (A.z + B.z)/ 2;
    return G;
 }
int main(){
    int n;
    cout << "Enter the number of points: "; cin >> n;
    Oxyz Point[n];
    cout << "Enter value of point in OXYZ: \n";
    for(int i = 0; i < n; i++){
        cin >> Point[i];
    }
    cout << "\nList Point in OXYZ: \n";
    for(int i  = 0; i < n; i++){
        cout <<"Point " << i+1 << ": " <<Point[i];
    }
    Oxyz O(0,0,0);
    cout << "Pairs of points are symmetrical about the center O in OXYZ space: \n";
    for(int i = 0; i < n - 1; i++){{
            if(Midpoint(Point[i],Point[i+1]).getX() == O.getX() &&
               Midpoint(Point[i],Point[i+1]).getY() == O.getY() &&
               Midpoint(Point[i],Point[i+1]).getZ() == O.getZ()){
                cout << "Pairs of point :"<< endl;
                cout << Point[i] << Point[i+1];
            }

        }
    }
    return 0;
}
