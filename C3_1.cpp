#include<iostream>
#include<cstring>
using namespace std;

class Person{
    private:
        char* name;
        int age;

    public:
        Person(char* myName, int myAge){
            int len = strlen(myName) + 1;
            name = new char[len];
            strcpy(name, myName);
            age = myAge;
        }

        Person(Person &refPerson)
        :name(refPerson.name), age(refPerson.age){
            name = new char[strlen(refPerson.name) + 1];
            strcpy(name, refPerson.name);
        }

        void showPersonInfo() const{
            cout << "이름 : " << name << endl;
            cout << "나이 : " << age << endl;
        }
        ~Person(){
            delete []name;
            cout<<"called destructor!"<<endl;
        }
};

int main(void){
    Person man1("lee", 29);
    Person man2 = man1;
    man1.showPersonInfo();
    man2.showPersonInfo();
    return 0;
}