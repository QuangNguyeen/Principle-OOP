#ifndef PRINCIPLE_OOP_POINT_H
#define PRINCIPLE_OOP_POINT_H
#include<iostream>
namespace std{
    class Point{
    public:
        int x, y;
    public:
        Point(){};
        Point(int x, int y){
            this->x = x;
            this->y = y;
        }
        ~Point(){};
        friend ostream &operator<<(ostream&out, Point point);
        friend istream &operator>>(istream&in, Point& point);
        bool CheoChinh(){
            return (this->x == this->y);
        }
    };
    ostream &operator<<(ostream&out, Point point){
        out << point.x << "\t" << point.y;
        return out;
    }
    istream &operator>>(istream&in, Point &point){
        in >> point.x >> point.y;
        return in;
    }
}
#endif //PRINCIPLE_OOP_POINT_H
