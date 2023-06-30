#include<iostream>
using namespace std;

struct FuncObject{
    void operator()(int n) const{
        cout << "함수 객체 : " << n << endl;
    }
};

void print(int n){
    cout << "n : " << n << endl;
}

int main(){
    // 함수 직접호출
    print(10);
    // 함수 포인터를 통한 호출
    void (*fp)(int);
    fp = print;
    fp(1);
    // 함수 객체 - Functor = 조건자
    FuncObject fp2;
    fp2(11);

    //람다식
    auto p = [](int n){cout << "n: " << n << endl;};
    p(1);
}