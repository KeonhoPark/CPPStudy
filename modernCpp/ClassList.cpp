#include<iostream>
#include<list>
#include<string>
using namespace std;

class Employee{
    private:
        string name;
        int number;

    public:
        Employee(string name, int number);
        void showInfo() const;
};

Employee::Employee(string name, int number) : name(name), number(number){};
void Employee::showInfo() const{
    cout << "name : " << name << " number : " << number << endl;
}

int main(){
    list<Employee> eList = {Employee("park", 1), Employee("kim", 2), Employee("lee", 3)};
    for(Employee e : eList){
        e.showInfo();
    }

    return 0;
}