#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    auto a = 18;
    auto d = 3.14;

    cout.fill('*');
    cout.width(10);
    cout << a << endl;
    cout.width(10);
    cout << d << endl;
    cout.fill(' ');
    cout << setw(10) << a << endl << setw(10) << d << endl;

    cout << hex << a << endl;
    cout << dec << a << endl;
    cout << a << endl;

    cout << fixed;
    cout.precision(2);
    cout << d;
    

    return 0;
}