#include<iostream>
#include<map>
#include<string>
using namespace std;

class Employee{
    private:
        string name;
        int number;

    public:
        Employee(string name, int number);
};

Employee::Employee(string name, int number) : name(name), number(number){};

int main(){
    map<string, int, less<string>> nameNum;
    // nameNum.insert(make_pair("park", 1));
    // nameNum.insert(make_pair("kim", 2));
    // nameNum.insert(make_pair("lee", 3));
    nameNum.insert({"park", 1});
    nameNum.insert({"kim", 2});
    nameNum.insert({"lee", 3});

    for(auto i : nameNum){
        cout << i.first << " " << i.second;
    }

    return 0;
}