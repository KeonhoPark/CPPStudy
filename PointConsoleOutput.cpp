#include<iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y) {}
        void showPosition() const{
            cout << "[" << xpos << ", " << ypos << "]" << endl;
        }
        friend ostream& operator<<(ostream&, const Point&);
        friend istream& operator>>(istream&, Point&);
};

ostream& operator<<(ostream& os, const Point& pos){
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}

istream& operator>>(istream& is, Point& pos){
    cout << "x, y 좌표 순으로 입력: ";
    is>>pos.xpos>>pos.ypos;
    return is;
}

int main(){
    // Point p1(1, 3);
    // cout<<p1;
    // Point p2(101, 303);
    // cout<<p2;

    Point p1;
    cin>>p1;
    cout<<p1;
    return 0;
}