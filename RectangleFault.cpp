#include<iostream>
using namespace std;

class Point{
    private:
        int x;
        int y;

    public:
        bool init(int posX, int posY){
            if((0 <= posX && posX <= 100) && (0 <= posY && posY <= 100)){
                x = posX;
                y = posY;
                return true;
            }
            else{
                cout << "잘못된 초기화" << endl;
                return false;
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
        bool init(const Point &ul, const Point &dr){
            if((ul.getX() > dr.getX()) || (ul.getY() > dr.getY())) {
                cout << "잘못된 위치정보" << endl;
                return false;
            }
            upLeft = ul;
            downRight = dr;
            return true;
        }

        void showRecInfo(){
            cout << "좌 상단: " << '[' << upLeft.getX() << ", " << upLeft.getY() << ']' << endl;
            cout << "우 하단: " << '[' << downRight.getX() << ", " << downRight.getY() << ']' << endl;
        }
};

int main(){
    Point p1;
    p1.init(3, 5);
    Point p2;
    p2.init(5, 9);
    Rectangle rect;
    rect.init(p1, p2);
    rect.showRecInfo();
    return 0;
}