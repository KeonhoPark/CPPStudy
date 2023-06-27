#include<iostream>
using namespace std;

class Shape{
    private:
        int length;
        int area;
        int surround;

    public:
        Shape(int len){
            length = len;
            area = 0;
            surround = 0;
        }

        bool setLength(int len){
            if(len <= 0){
                return false;
            }
            length = len;
            return true;
        }

        int getLength(){
            return length;
        }

        virtual void calcAndSetArea(){
            return;
        }

        virtual void calcAndSetSurround(){
            return;
        }

        virtual double getArea() const{
            return 0;
        }

        virtual double getSurround() const{
            return 0;
        }

        virtual void showShapeInfo() const{
            cout << "shape area : " << area << endl;
            cout << "shape surround : " << surround << endl;
        }
};

class Circle : public Shape{
    private:
        double area;
        double surround;
        const double PI = 3.14;

    public:
        Circle(int len) : Shape(len){
            area = 0;
            surround = 0;
        }

        void calcAndSetArea(){
            int len = getLength();
            area = double(len * len * PI);
        }

        virtual double getArea() const{
            return area;
        }

        void calcAndSetSurround(){
            int len = getLength();
            surround = 2 * PI * len;
        }

        virtual double getSurround() const{
            return surround;
        }

        virtual void showShapeInfo() const{
            cout << "circle area : " << area << endl;
            cout << "circle surround : " << surround << endl;
        }
};

class Square : public Shape{
    private:
        double area;
        double surround;

    public:
        Square(int len) : Shape(len){
            area = 0;
            surround = 0;
        }

        void calcAndSetArea(){
            int len = getLength();
            area = double(len * len);
        }

        virtual double getArea() const{
            return area;
        }

        void calcAndSetSurround(){
            int len = getLength();
            surround = 4 * len;
        }

        virtual double getSurround() const{
            return surround;
        }

        virtual void showShapeInfo() const{
            cout << "square area : " << area << endl;
            cout << "square surround : " << surround << endl;
        }
};

class Triangle : public Shape{
    private:
        double area;
        double surround;

    public:
        Triangle(int len) : Shape(len){
            area = 0;
            surround = 0;
        }

        void calcAndSetArea(){
            int len = getLength();
            area = double(len * len) / 2;
        }

        virtual double getArea() const{
            return area;
        }

        void calcAndSetSurround(){
            int len = getLength();
            surround = 3 * len;
        }

        virtual double getSurround() const{
            return surround;
        }

        virtual void showShapeInfo() const{
            cout << "triangle area : " << area << endl;
            cout << "triangle surround : " << surround << endl;
        }
};

int main(){
    Shape* c1 = new Circle(7);
    c1->calcAndSetArea();
    c1->calcAndSetSurround();
    c1->showShapeInfo();

    Shape* s1 = new Square(7);
    s1->calcAndSetArea();
    s1->calcAndSetSurround();
    s1->showShapeInfo();

    Shape* t1 = new Triangle(7);
    t1->calcAndSetArea();
    t1->calcAndSetSurround();
    t1->showShapeInfo();
   
    return 0;
}