#include<iostream>
using namespace std;

//template <typename T> 도 가능
template <typename T1, typename T2>
T2 add(const T1 n1, const T2 n2){
    return n1 + n2;
}

// int add(int n1, int n2){
//     return n1 + n2;
// }

// double add(double n1, double n2){
//     return n1 + n2;
// }

int main(){
    cout << add<int, int>(3, 5) << endl;
    cout << add<double, double>(4.5, 2.5) << endl;
    cout << add<int, double>(3, 5.5)<<endl;
    return 0;
}