#include<iostream>
using namespace std;

class SoSimple{
    private:
        int num;

    public:
        SoSimple(int num) : num(num){};

        SoSimple& addNum(int num){
            this->num += num;
            return *this;
        }

        void simpleFunc(){
            cout << "SimpleFunc : " << num << endl;
        }

        void simpleFunc() const{
            cout << "SimpleFunc const: " << num << endl;
        }
};

void yourFunc(const SoSimple &ss){
    ss.simpleFunc();
}

int main(){
    SoSimple s1(100);
    const SoSimple s2(10);

    s1.simpleFunc();
    s2.simpleFunc();

    yourFunc(s1);
    yourFunc(s2);
    return 0;
}