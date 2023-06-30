#include<iostream>
#include<algorithm>
using namespace std;

struct myGreater{
    bool operator()(int a, int b){
        return a > b;
    }
};

int main(){
    int arr[5] = {3, 1, 5, 2, 4};
    sort(arr, arr + 5, myGreater());

    for(int i = 0; i < 5; i++){
        cout << arr[i] << endl;
    }
}