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
            name = new char[len];
            strcpy(name, myname);
            age = myage;
        }

        Person(){
            name = NULL;
            age = 0;
            cout << "called Person()" << endl;
        }

        void setPersonInfo(char* myname, int myage){
            name = myname;
            age = myage;
        }

        void showPersonInfo() const{
            cout<<"이름 : "<<name<<" 나이 : "<<age<<endl;
        }

        ~Person(){
            delete[] name;
            cout<<"called destructor"<<endl;
        }
};

int main(){
    Person* parr[3];
    char namestr[100];
    int age;

    for(int i = 0; i < 3; i++){
        cout<<"이름 : ";
        cin>>namestr;
        cout<<"나이 : ";
        cin>>age;
        parr[i] = new Person(namestr, age);
    }

    for(int i = 0; i < 3; i++){
        parr[i]->showPersonInfo();
    }

    for(int i = 0; i < 3; i++){
        delete parr[i];
    }

    return 0;
}