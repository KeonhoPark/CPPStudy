#include<iostream>
#include<exception>
using namespace std;

int main(){
    try
    {
        int a, b = 0;
        cin >> a, b;
        if(b == 0) throw "DivideByZero";
        int res = a / b;
    } catch(...){
        cout << "예외발생" << endl;
    }

    cout << "end program" << endl;
    return 0;
}