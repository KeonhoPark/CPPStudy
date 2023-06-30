#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> arr = {3, 4, 1, 2, 5};
    for_each(arr.begin(), arr.end(), [](int &n){n++;});
    for(auto it = arr.begin(); it != arr.end(); it++){
        cout << *it;
    }
    return 0;
}