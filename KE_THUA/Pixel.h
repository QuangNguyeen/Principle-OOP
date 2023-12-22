#ifndef PRINCIPLE_OOP_PIXEL_H
#define PRINCIPLE_OOP_PIXEL_H
#include<istream>
#include"Color.h"
#include"Point.h"
namespace std{
    class Pixel:public Point, public Color{
    public:
        Pixel(){};
        Pixel(int x, int y, string TenMau, string MaMau): Point(x,y), Color(TenMau, MaMau){};
        friend istream& operator>>(istream&in, Pixel &pixel);
        friend ostream& operator<<(ostream&out, Pixel pixel);
        bool KiemTra(){
            return (this->CheoChinh() && this->TenMau == "Green");
        }
    };
    ostream & operator <<(ostream&out, const Pixel& pixel){
        cout << endl;
        out << "x: " << pixel.x << "\t" << "y: " << pixel.y << "\t" << "Ten: " << pixel.TenMau << "\t" << pixel.MaMau;
        return out;
    }
    istream & operator >> (istream&in, Pixel& pixel){
        Color &color = pixel;
        Point &point = pixel;
        in >> point >> color;
        return in;
    }
}
#endif //PRINCIPLE_OOP_PIXEL_H
