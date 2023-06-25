#include <iostream>
using namespace std;

void change(int &ref){
    ref *= -1;
}

int main(){
    int a = -1;
    change(a);
    cout << a;
    return 0;
}