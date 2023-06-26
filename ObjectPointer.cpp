#include <iostream>
using namespace std;

class Person{
    public:
        void sleep(){
            cout << "Sleep" << endl;
        }
};

class Student : public Person{
    public:
        void study(){
            cout << "study" << endl;
        }
};

class PartTimeStudent : public Student{
    public:
        void Work(){
            cout << "Work" << endl;
        }
};

int main(){
    Person* ptr1 = new Student();
    Person* ptr2 = new PartTimeStudent();
    Student* ptr3 = new PartTimeStudent();
    Student* ptr4 = new Person();
    ptr1->sleep();
    ptr2->sleep();
    ptr3->study();
    ptr4->sleep();
    ptr4->study();
    delete ptr1; delete ptr2; delete ptr3;
    return 0;
}