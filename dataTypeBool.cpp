#include <iostream>
using namespace std;

bool isPositive(int num){
    if(num <= 0){
        return false;
    }
    else{
        return true;
    }
}

int main() {
    int num = -3;

    if(isPositive(num)){
        cout << "positive number" << endl;
    }
    else{
        cout << "negative number" << endl;
    }
    return 0;
}