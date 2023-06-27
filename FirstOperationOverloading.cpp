#include<iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y){}
        void showPosition() const{
            cout << "[" << xpos <<", " << ypos << ']' << endl;
        }
        Point operator+(const Point &ref){
            Point pos(xpos + ref.xpos, ypos + ref.ypos);
            return pos;
        }
        Point operator-(const Point &ref){
            Point pos(xpos - ref.xpos, ypos - ref.ypos);
            return pos;
        }
        Point operator*(const Point &ref){
            Point pos(xpos * ref.xpos, ypos * ref.ypos);
            return pos;
        }
        Point operator/(const Point &ref){
            Point pos(xpos / ref.xpos, ypos / ref.ypos);
            return pos;
        }
};

int main(void){
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3 = pos1.operator+(pos2);
    Point pos4 = pos1.operator-(pos2);
    Point pos5 = pos1.operator*(pos2);
    Point pos6 = pos1.operator/(pos2);
    
    pos1.showPosition();
    pos2.showPosition();
    pos3.showPosition();
    pos4.showPosition();
    pos5.showPosition();
    pos6.showPosition();
    return 0;
}