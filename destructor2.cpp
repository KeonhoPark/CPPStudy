#include<iostream>
#include<cstring>
using namespace std;

class Person{
    private:
        char* name;
        int age;
    
    public:
        Person(char* name, int age){
            int len = strlen(name)+1;
            this->name = new char[len];
            strcpy(this->name, name);
            this->age = age;
        }

        void showPersonInfo() const{
            cout << "이름 : " << this->name << endl;
            cout << "나이 : " << this->age << endl;
        }

        ~Person(){
            delete this->name;
            cout << "called destructor!!" << endl;
        }
};

int main(){
    Person p1("park", 13);
    p1.showPersonInfo();
    return 0;
}