#include<iostream>
#include<cmath>
using namespace std;
class Point{
private:
    double x, y;
public:
    Point() : x(), y(){}; // Constructor
    ~Point(){}; // Destructor
    void input(){
        cout << "Enter value of x: "; cin >> x;
        cout << "Enter value of y: "; cin >> y;
    }
    double distance(Point point) const{
        return sqrt(pow(this->x - point.x, 2) + pow(this->y-point.y,2));
    }
    void output(){
        cout << "x: " << x << "\t" << "y: " << y << endl;
    }
};
int main(){
    int n;
    double maxDistance = 0;
    cout << "Enter the number of Points: ";
    cin >> n;
    Point *listPoint[n];
    for(int i = 0; i < n; i++){
        listPoint[i] = new Point;
        listPoint[i]->input();
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(listPoint[i]->distance(*listPoint[j]) > maxDistance){
                maxDistance = listPoint[i]->distance(*listPoint[j]);
            }
        }
    }
    cout << "Max Distance : " << maxDistance;
    return 0;
}