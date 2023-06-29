#include "Circle.h"

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