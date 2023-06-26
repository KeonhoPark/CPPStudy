#include<iostream>
using namespace std;

typedef struct __Point{
    int xpos;
    int ypos;
} Point;

Point& pntAdder(const Point &p1, const Point &p2){
    Point* newP = new Point;
    newP -> xpos = p1.xpos + p2.xpos;
    newP -> ypos = p1.ypos + p2.ypos;
    return *newP;
}

int main(){
    Point* p1 = new Point;
    Point* p2 = new Point;
    p1 -> xpos = 10;
    p1 -> ypos = 20;
    p2 -> xpos = 30;
    p2 -> ypos = 40;

    Point &resP = pntAdder(*p1, *p2);
    cout << "res x : " << resP.xpos << "res y : " << resP.ypos << endl;
    return  0;
}