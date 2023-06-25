#include<iostream>
using namespace std;

int& funcOne(int &ref){
    ref += 10;
    return ref;
}

int main(){
    int n1 = 10;
    int n2 = funcOne(n1);
    n2++;

    cout << "n1 : " << n1 << endl;
    cout << "n2 : " << n2 << endl;
    return 0;
}