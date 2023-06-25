#include <iostream>
using namespace std;

void swapByRef(int &ref1, int &ref2){
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

int main(){
    int a = 10;
    int b = 20;

    swapByRef(a, b);
    cout << "a : " << a << " b : " << b << endl;
    return 0;
}