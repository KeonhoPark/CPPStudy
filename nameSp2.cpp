#include<iostream>
using namespace std;

int a = 5;

int main(){
    int a = 3;
    cout << "local " << a << endl;
    cout << "global " << ::a << endl;
    return 0;
}

