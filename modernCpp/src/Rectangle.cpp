#include "Rectangle.h"

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