#include<iostream>
#include<cstring>
using namespace std;

class Person{
    private:
        char* name;
        int age; 

    public:
        Person(char* myname, int myage){
            int len = strlen(myname);
            name = new char[len + 1];
            strcpy(name, myname);
            age = myage;
        }

        // Person(Person &ref){
        //     int len = strlen(ref.name);
        //     name = new char[len + 1];
        //     strcpy(name, ref.name);
        //     age = ref.age;
        // }

        Person(Person &ref) : name(ref.name), age(ref.age){}

        void showPersonInfo() const{
            cout << "이름 : " << name << endl;
            cout << "나이 : " << age << endl;
        }

        ~Person(){
            cout << "called destructor " << static_cast<const void*>(name) << endl;
            delete []name;
        }
};

void foo(){
    int age;
    char name[1000];
    cin >> name >> age;
    Person newPerson(name, age);
    newPerson.showPersonInfo();
}

int main(){
    foo();
    foo();
    return 0;
}
