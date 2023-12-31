#include <iostream>
using namespace std;

class Shape
{
private:
    int xpos;
    int ypos;

public:
    Shape(int x, int y);
    virtual void draw();
    virtual double getArea() const;
};

Shape::Shape(int x, int y){
    xpos = x;
    ypos = y;
}

Shape::virtual void draw(){
    cout << "xpos : " << xpos << endl;
    cout << "ypos : " << ypos << endl;
}

virtual double Shape::getArea() const{
    return 0;
}


class Circle : public Shape
{
    private:
        double radius;

    public:
        Circle(int x, int y, int r) : Shape(x, y);

        void draw();


        double getArea() const;

        double getArea() const{
            return radius * radius * 3.14;
        }
};

Circle::Circle(int x, int y, int r) : Shape(x, y){
    radius = r;
}

void Circle::draw(){
    Shape::draw();
    cout << "radius : " << radius << endl;
}

double Circle::getArea() const{
    return radius * radius * 3.14;
}

class Rectangle : public Shape
{
    private:
        int width;
        int height;

    public:
        Rectangle(int x, int y, int w, int h) : Shape(x, y);
        void draw();
        double getArea() const;
};

Rectangle::Rectangle(int x, int y, int w, int h) : Shape(x, y){
    width = w;
    height = h;
}

void Rectangle::draw(){
    Shape::draw();
    cout << "width : " << width << " " << "height : " << height << endl;
}

double Rectangle::getArea() const{
    return width * height;
}


int main()
{
    const int size = 2;
    Shape *p[size];
    p[0] = new Rectangle(10, 10, 5, 8);
    p[1] = new Circle(10, 10, 5);

    for (int i = 0; i < size; i++){
        p[i]->draw();
        cout << "면적 : " << p[i]->getArea() << endl;
    }

    for (int i = 0; i < size; i++){
        delete p[i];
    }
}