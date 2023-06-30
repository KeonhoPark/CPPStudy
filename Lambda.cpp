#include<iostream>
using namespace std;

int main(){

    auto r = [](int a, int b) -> int {return a + b;}(10, 20);
    auto r = [](int a, int b){return a + b;}(10, 20);
    int s = 3;
    auto square = [](int a){return a * a;};
    auto square1 = [](int a) -> int{return a * a;};
    double pi = 3.14;
    auto area = [pi](int i){return pi * i * i;};
    auto area2 = [&pi](int i){pi = 3.141592; return pi * i * i;};

    int a = 10;
    int b = 20;
    auto print = [=](){cout << a << " " << b << endl;};
    auto alter = [&](){cout << a << " " << b << endl;};
    print();
    alter();

    cout << r << endl;
    cout << square(3) << endl;
    cout << square1(3) << endl;
    cout << area(3) << endl;
    cout << area2(5) << endl;

    return 0;
}