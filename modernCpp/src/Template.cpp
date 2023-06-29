#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//template <typename T> 도 가능
template <typename T1, typename T2>
T2 add(T1 n1, T2 n2){
    return n1 + n2;
}

template<typename T>
T Max(T n1, T n2){
    // if(n1 >= n2){
    //     return n1;
    // }
    // else{
    //     return n2;
    // }

    return n1 > n2 ? n1 : n2;
}

char* Max(char* a, char* b){
    if(strcmp(a, b) > 0) return a;
    else return b;
}

int main(){
    char s1[10] = "hello";
    char s2[10] = "world";
    cout << max(s1, s2) << endl;

    cout << add<int, int>(3, 5) << endl;
    cout << add<double, double>(4.5, 2.5) << endl;
    cout << add<int, double>(3, 5.5)<<endl;

    int x = 10, y = 20;
    cout << Max(x, y) << endl;

    double dx = 3.4;
    double dy = 5.6;
    cout << Max(dx, dy) << endl;

    return 0;
}