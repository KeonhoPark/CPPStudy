#include<iostream>
using namespace std;

void swapPointer(int* ptr1, int* ptr2){
    int tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}

int main(){
    int n1 = 1;
    int n2 = 2;
    swapPointer(&n1, &n2);
    cout << n1 << " " << n2 << endl;

    return 0;
}