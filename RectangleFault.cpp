#include<iostream>
using namespace std;

class Point{
    private:
        int x;
        int y;

    public:
        Point(int posX, int posY){
            if((0 <= posX && posX <= 100) && (0 <= posY && posY <= 100)){
                x = posX;
                y = posY;
                return;
            }
            else{
                cout << "잘못된 초기화" << endl;
                return;
            }
        }

        int getX() const{
            return x;
        }

        int getY() const{
            return y;
        }

        bool setX(int posX){
            if(posX < 0 || posX > 100) return false;
            x = posX;
            return true;
        }

        bool setY(int posY){
            if(posY < 0 || posY > 100) return false;
            y = posY;
            return true;
        }
};

class Rectangle{
    private:
        Point upLeft;
        Point downRight;

    public:
        Rectangle(const Point &ul, const Point &dr) : upLeft(ul.getX(), ul.getY()), downRight(dr.getX(), dr.getY()) {
            if((ul.getX() > dr.getX()) || (ul.getY() > dr.getY())) {
                cout << "잘못된 위치정보" << endl;
                return;
            }
            upLeft = ul;
            downRight = dr;
            return;
        }

        void showRecInfo(){
            cout << "좌 상단: " << '[' << upLeft.getX() << ", " << upLeft.getY() << ']' << endl;
            cout << "우 하단: " << '[' << downRight.getX() << ", " << downRight.getY() << ']' << endl;
        }
};

int main(){
    Point p1(3, 5);
    Point p2(5, 9);
    Rectangle rect(p1, p2);
    rect.showRecInfo();
    return 0;
}