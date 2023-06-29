#include"Shape.h"
#include"Circle.h"
#include"Rectangle.h"
#include<iostream>
using namespace std;

int main()
{

    string s = "hello";
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

    return 0;
}
