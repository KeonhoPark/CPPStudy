#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<functional>
using namespace std;

int main(){
    vector<int> arr = {4, 6, 2, 1};
    
    for(auto it = arr.begin(); it != arr.end(); it++){
        cout << *it << " ";
    }

    cout << endl;

    sort(arr.begin(), arr.end(), greater<int>());

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    sort(arr.begin(), arr.end(), [](int a, int b){return a < b;});

    for(auto i : arr){
        cout << i << " ";
    }

    return 0;
}