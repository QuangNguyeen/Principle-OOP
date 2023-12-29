#include<iostream>
using namespace std;
class Color{
protected:
    string MaMau, TenMau;
public:
    // Constructor no parameter
    Color(){};
    // Constructor
    Color(string id, string name){
        this->MaMau = id;
        this->TenMau = name;
    }
    // Destructor
    ~Color(){};
    string getTenMau(){
        return TenMau;
    }
    // Overload
    friend istream & operator >> (istream & in, Color & color);
    friend ostream & operator << (ostream & out, Color color);
};
istream & operator >> (istream & in, Color & color){
    cout << "Enter color code: "; in >> color.MaMau;
    cout << "Enter color name: "; in >> color.TenMau;
    return in;
}
ostream & operator << (ostream & out, Color color){
    cout << "Color code: " << color.MaMau << "\n" << "Color name: " << color.TenMau;
    return out;
}
class Point{
protected:
    int x, y;
public:
    Point(){};
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    ~Point(){};
    bool CheoChinh(){
        return x == y;
    }
    friend istream & operator >> (istream & in, Point & point);
    friend ostream & operator << (ostream & out, Point point);
};
istream & operator >> (istream & in, Point & point){
    cout << "Enter value of x: "; in >> point.x;
    cout << "Enter value of y: "; in >> point.y;
    return in;
}
ostream & operator << (ostream & out, Point point){
    out << "x: " << point.x << "\t" << "y: " << point.y;
    return out;
}
class Pixel : public Color, public Point{
public:
    Pixel(){};
    Pixel(int x, int y, string TenMau, string MaMau): Point(x,y), Color(TenMau, MaMau){};
    friend istream & operator >> (istream & in, Pixel & pixel);
    friend ostream & operator << (ostream & out, Pixel pixel);
    bool KiemTra(){
        return  this->CheoChinh() && TenMau == "Green";
    }
};
istream & operator >> (istream & in, Pixel & pixel){
    Color & color = pixel;
    Point & point = pixel;
    in >> point >> color;
    return in;
}
ostream & operator << (ostream & out, Pixel pixel){
    Color & color = pixel;
    Point & point = pixel;
    out << color << "\n" << point ;
    return out;
}
int main(){
    int n;
    cout << "Enter number of the pixels: "; cin >> n;
    Pixel listPixel[n];
    for(int i = 0; i < n; i++){
        cin >> listPixel[i];
    }
    cout << "List Pixels:\n";
    for(int i = 0; i < n; i++){
        if(listPixel[i].KiemTra()){
            cout << listPixel[i] << endl;
        }
    }
    return 0;
}
