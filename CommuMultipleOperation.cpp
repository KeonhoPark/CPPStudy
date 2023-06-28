#include<iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y) {}
        void showPosition() const{
            cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
        }
        Point operator*(int times){
            Point pos(xpos * times, ypos * times);
            return pos;
        }
        friend Point operator*(int times, Point &ref);
};

Point operator*(int times, Point &ref){
    return ref * times;
}

int main(){
    Point p1(2, 3);
    Point p2;

    p2 = 3 * p1;

    p1.showPosition();
    p2.showPosition();
    return 0;
}