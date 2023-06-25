#include<iostream>
using namespace std;

int main(){
    const int num = 10;
    const int* ptr = &num;
    const int* &ref = ptr;

    cout << "*ptr : " << *ptr << endl;
    cout << "*ref : " << *ref << endl;

    return 0;
}