#include<iostream>
using namespace std;

struct Point{
    int xpos;
    int ypos;

    void movePos(int x, int y){
        xpos += x;
        ypos += y;
    }

    void addPoint(const Point &pos){
        xpos += pos.xpos;
        ypos += pos.ypos;
    }

    void showPosition(){
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

int main(){
    Point p1 = {12, 4};
    Point p2 = {20, 30};

    p1.movePos(-7, 10);
    p1.showPosition();
    p1.addPoint(p2);
    p1.showPosition();
    return 0;
}