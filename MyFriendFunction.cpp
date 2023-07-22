#include<iostream>
using namespace std;

class Point;

class PointOP{
    private:
        int opcnt;

    public:
        PointOP() : opcnt(0) {}

        Point pointAdd(const Point&, const Point&);
        Point pointSub(const Point&, const Point&);
        ~PointOP(){
            cout << "operation times : " << opcnt << endl;
        }
};

class Point{
    private:
        int x;
        int y;

    public:
        Point(const int &xpos, const int &ypos) : x(xpos), y(ypos) {};
        friend Point PointOP::pointAdd(const Point&, const Point&);
        friend Point PointOP::pointSub(const Point&, const Point&);
        friend void showPointPos(const Point&);
};

Point PointOP::pointAdd(const Point &p1, const Point &p2){
    opcnt++;
    return Point(p1.x + p2.x, p1.y + p2.y);
}

Point PointOP::pointSub(const Point &p1, const Point &p2){
    opcnt++;
    return Point(p1.x - p2.x, p1.y - p2.y);
}

int main(){
    Point p1(1, 2);
    Point p2(3, 4);
    PointOP op;

    showPointPos(op.pointAdd(p1, p2));
    showPointPos(op.pointSub(p1, p2));
    return 0;
}

void showPointPos(const Point& pos){
    cout << "x : " << pos.x << ", ";
    cout << "y : " << pos.y << endl;
}