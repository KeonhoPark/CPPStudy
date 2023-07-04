#include<iostream>
using namespace std;

class AAA{
    public:
        AAA(){
            cout<<"empty object"<<endl;
        }

        void showYourName(){
            cout<<"AAA"<<endl;
        }
};

class BBB{
    private:
        AAA &ref;
        const int &num;

    public:
        BBB(AAA &r, const int &n) : ref(r), num(n){}
        void showYourName(){
            ref.showYourName();
            cout<<"refNum : "<<num<<endl;
        }
};

int main(){
    AAA obj1;
    BBB obj2(obj1, 3);
    obj2.showYourName();
    return 0;
}