#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

char* makeArray(int len){
    char* arr = (char*)malloc(len * (int)(sizeof(char)));
    return arr;
}

int main(){
    char* arr = makeArray(3);
    strcpy(arr, "abc");

    cout << "arr : " << arr << endl;
    free(arr);
}