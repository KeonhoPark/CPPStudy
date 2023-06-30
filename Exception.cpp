#include<iostream>
#include<exception>
using namespace std;

class MyException{};

class DivideByZeroException : public MyException{};

void divide(int const num1, int const num2){
    try{
        if(num2 == 0){
            throw DivideByZeroException();
        }
    }
    catch(DivideByZeroException &e){
        throw e;
    }
}

int main(){
    try
    {
        int a, b = 0;
        cin >> a, b;
        divide(a, b);
    } catch(DivideByZeroException &e){
        cout << "0으로 나눌 수 없음." << endl;
    }
    catch(MyException &e){
        cout << "myException" << endl;
    }

    catch(DivideByZeroException &e){
        cout << "0으로 나눌 수 없음." << endl;
    }

    cout << "end program" << endl;

    double a = (double)1/3;
    cout.precision(2);
    cout << a << endl;
    return 0;
}