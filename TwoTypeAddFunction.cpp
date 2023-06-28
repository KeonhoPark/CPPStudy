#include<iostream>
using namespace std;

template<typename T>
T add(T n1, T n2){
    cout<<"template add"<<endl;
    return n1 + n2;
}

int add(int n1, int n2){
    cout<<"int add"<<endl;
    return n1 + n2;
}

double add(double n1, double n2){
    cout<<"double add"<<endl;
    return n1 + n2;
}

int main(){
    cout<<add(3, 4)<<endl;
    cout<<add(3.1, 4.3)<<endl;
    cout<<add<int>(3, 4)<<endl;
    cout<<add<double>(3.1, 4.3)<<endl;
    return 0;
}