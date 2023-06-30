#include<iostream>
#include<list>
using namespace std;

int main(){
    // list<int> arr;
    // arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(3);

    //uniform initializer
    list<int> arr = {1, 2, 3};

    for(auto it = arr.begin(); it != arr.end(); it++){
        cout << *it;
    }

    cout << endl;
    arr.insert(arr.end(), 4);
    auto it = arr.begin();
    for(int i = 0; i < 2; i++){
        it++;
    }
    arr.insert(it, 2);
    // arr.insert(arr + 2, 2);
    arr.erase(it);

    //ranged for
    for(auto i : arr){
        cout << i;
    }
}