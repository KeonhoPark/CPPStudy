#include<iostream>
using namespace std;

void swapByPointer(int* &ref1, int* &ref2){
    int temp = *ref1;
    *ref1 = *ref2;
    *ref2 = temp;
}

int main(){
    int a = 10;
    int* ptr1 = &a;
    int b = 20;
    int* ptr2 = &b;
    swapByPointer(ptr1, ptr2);

    cout << "a : " << a << endl;
    cout << "b : " << b << endl;
}