#include<iostream>
using namespace std;

class SoSimple{
    private:
        int num1;
        int num2;

    public:
        SoSimple() = default;

        SoSimple(int n1, int n2) : num1(n1), num2(n2){
            cout << "called SoSimple(int n1, int n2)" << endl;
        }

        SoSimple(const SoSimple &ref) : num1(ref.num1), num2(ref.num2){
            cout << "called SoSimple(SoSimple &ref)" << endl;
        }

        void showSimpleData(){
            cout << num1 << endl;
            cout << num2 << endl;
        }
};

int main(){
    SoSimple s1(1, 2);
    SoSimple s2 = s1;
    cout << "생성 및 초기화 직전" << endl;
    cout << "생성 및 초기화 직후" << endl;
    s1.showSimpleData();
    s2.showSimpleData();
    return 0;
}