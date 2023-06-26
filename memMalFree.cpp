#include<iostream>
#include<cstring>

using namespace std;

char* makeArray(int len){
    char* arr = new char[len];
    return arr;
}

int main(){
    // char* arr = makeArray(3);
    // strcpy(arr, "abc");

    int* a = new int;
    int& ref = *a;
    ref = 10;
    cout << "ref : " << ref;

    // cout << "arr : " << arr << endl;
    delete []a;
}