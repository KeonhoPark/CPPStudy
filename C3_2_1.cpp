#include <iostream>
using namespace std;

class Calculator{
    private:
        int add;
        int sub;
        int mul;
        int div;

    public:
        void init();
        double Add(double n1, double n2);
        double Sub(double n1, double n2);
        double Mul(double n1, double n2);
        double Div(double n1, double n2);
        void showOpCount();
};

void Calculator::init(){
    add = 0;
    sub = 0;
    mul = 0;
    div = 0;
}

double Calculator::Add(double n1, double n2){
    return n1 + n2;
}

double Calculator::Sub(double n1, double n2){
    return n1 - n2;
}

double Calculator::Mul(double n1, double n2){
    return n1 * n2;
}

double Calculator::Div(double n1, double n2){
    return n1 / n2;
}

void Calculator::showOpCount(){
    cout << "덧셈: " << add << "뺄셈: " << sub << "곱셈: " << mul << "나눗셈: " << div << endl;
}

int main(){
    Calculator calc;
    calc.init();
    cout << "3.2 + 2.4 = " << calc.Add(3.2, 2.4) << endl;
    cout << "3.2 - 2.4 = " << calc.Sub(3.2, 2.4) << endl;
    cout << "3.2 * 2.4 = " << calc.Mul(3.2, 2.4) << endl;
    cout << "3.2 / 2.4 = " << calc.Div(3.2, 2.4) << endl;
    calc.showOpCount();
    return 0;
}
