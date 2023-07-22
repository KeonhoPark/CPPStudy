#include<iostream>
using namespace std;

class SoSimple{
    private:
        int num;

    public:
        SoSimple(int num) : num(num){
            cout << "new object : " << this << endl;
        }

        SoSimple(const SoSimple &ss) : num(ss.num){
            cout << "new object copy : " << this << endl;
        }

        ~SoSimple(){
            cout << "destroy object" << this << endl;
        }
};

SoSimple simpleFunc(SoSimple ob){
    cout << "Parm ADR : " << &ob << endl;
    return ob;
}

int main(){
    SoSimple obj(3);
    simpleFunc(obj);

    cout << endl;
    SoSimple temp = simpleFunc(obj);
    cout << "return obj" << &temp << endl;
    return 0;
}   