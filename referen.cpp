#include <iostream>
using namespace std;

int main(){

    int num = 10;
    int &numRef = num;
    int &numRef2 = numRef;
    numRef = 15;

    cout << "num : " << num << endl;
    cout << "numRef : " << numRef << endl;
    cout << "numRef2 : " << numRef2 << endl;

    num = 12;

    cout << "num : " << num << endl;
    cout << "numRef : " << numRef << endl;
    cout << "numRef2 : " << numRef2 << endl;

    numRef2 = 17;

    cout << "num : " << num << endl;
    cout << "numRef : " << numRef << endl;
    cout << "numRef2 : " << numRef2 << endl;

    return 0;
}