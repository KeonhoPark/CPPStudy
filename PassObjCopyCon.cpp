#include<iostream>
using namespace std;

class SoSimple{
    private:
        int num;
    public:
        SoSimple(int num) : num(num){};
        SoSimple(SoSimple &ss) : num(ss.num){
            cout << "called copy constructor" << endl;
        }
        void showData(){
            cout << "num : " << num << endl;
        }
};

void simpleFunc(SoSimple ob){
    ob.showData();
}

int main(){
    SoSimple s1(3);
    simpleFunc(s1);
    return 0;
}