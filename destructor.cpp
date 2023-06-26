#include<iostream>
using namespace std;

class A{
    public:
        int num;
        A(int n){
            this->num = n;
            cout << "유저정의 생성자" << endl;
        }

        ~A(){
            cout << "유저정의 소멸자" << endl;
            delete this;
        }
};

int main(){
    A* newA = new A(10);
    delete newA;
}