#include<iostream>
using namespace std;

class SoSimple{
    private:
        int num;
    public:
        SoSimple(int num) : num(num){};
        SoSimple(const SoSimple &ss) : num(ss.num) {
            cout << "called copy constructor" << endl;
        }
        SoSimple& addNum(int n){
            num += n;
            return *this;
        }
        void showData(){
            cout << "num : " << this->num << endl;
        }
};

SoSimple simpleFunc(SoSimple ob){
    cout << "before return" << endl;
    return ob;
}

int main(){
    SoSimple s1(3);
    simpleFunc(s1).addNum(30).showData();
    s1.showData();
    return 0;
}