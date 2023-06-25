#include <iostream>
using namespace std;

void addOne(int &ref){
    ref++;
}

int main(){
    int a = 5;
    addOne(a);
    cout << a << endl;
    return 0;
}