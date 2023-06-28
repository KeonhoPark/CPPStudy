#include<iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        void init(int x, int y){
            xpos = x;
            ypos = y;
        }
        void showPointInfo() const{
            cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
        }
};

class Circle{
    private:
        Point center;
        int radius;
    
    public:
        init(int x, int y, int r){
            center.init(x, y);
            radius = r;
        }

        void showCircleInfo() const{
            cout<<"radius: "<<radius<<endl;
            center.showPointInfo();
        }
};

class Ring{
    private:
        Circle innerCircle;
        Circle outerCircle;

    public:
        init(int inX, int inY, int inR, int outX, int outY, int outR){
            innerCircle.init(inX, inY, inR);
            outerCircle.init(outX, outY, outY);
        }

        void showRingInfo(){
            cout<<"Inner Circle Info..."<<endl;
            innerCircle.showCircleInfo();
            cout<<"Outer Circle Info..."<<endl;
            outerCircle.showCircleInfo();
        }
};

int main(){
    Ring ring;
    ring.init(1, 1, 4, 2, 2, 9);
    ring.showRingInfo();
    return 0;
}