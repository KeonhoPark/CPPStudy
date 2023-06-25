#include<iostream>
#include<cstring>

using namespace std;

char* makeArray(int len){
    char* arr = new char[len];
    return arr;
}

int main(){
    char* arr = makeArray(3);
    strcpy(arr, "abc");

    cout << "arr : " << arr << endl;
    delete []arr;
}