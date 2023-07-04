#include<iostream>
using namespace std;

class SimpleClass{
    private:
        int num1;
        int num2;

    public:
        SimpleClass(int n1 = 0, int n2 = 0){
            num1 = n1;
            num2 = n2;
        }

        void showData() const{
            cout << num1 << " " << num2 << endl;
        }
};

int main(){
    SimpleClass s1();
    SimpleClass s2 = s1();
    s2.showData();
    return 0;
}

SimpleClass s1(){
    SimpleClass sc(20, 30);
    return sc;
}