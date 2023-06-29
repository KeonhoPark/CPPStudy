#include "Shape.h"

Shape::Shape(int x, int y){
    xpos = x;
    ypos = y;
}

void Shape::draw(){
    cout << "xpos : " << xpos << endl;
    cout << "ypos : " << ypos << endl;
}

double Shape::getArea() const{
    return 0;
}