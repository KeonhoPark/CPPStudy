#include<iostream>
using namespace std;

void addOne(int &num){
    num += 1;
}

int main(){
    int n = 3;
    addOne(n);
    cout << n << endl;

    return 0;
}