#include<iostream>
#include<cstring>
using namespace std;

class Student{
	private:
		int studentNumber;
		string studentName;
		
	public:
		Student();
		Student(int, string);
		int getStudentNumber();
		string getStudentName();
		bool setStudentNumber(int);
		bool setStudentName(string);
		
};

class School{
	private:
		string schoolName;
		Student* students;
		
	public:
		School();
        School(string name, Student *arr[3]);
        string getSchoolName();
		Student* getStudents();
		bool setSchoolName(string name);
		void setStudents(Student arr[3], int studentListCount);
};

Student::Student(int number, string name){
	studentNumber = number;
	studentName = name;
}
		
int Student::getStudentNumber(){
	return studentNumber;
}
		
string Student::getStudentName(){
	return studentName;
}
		
bool Student::setStudentNumber(int number){
	if(number < 1){
		return false;
	}
	studentNumber = number;
	return true;
}
		
bool Student::setStudentName(string name){
	if(name.length() > 5){
		return false;
	}
	studentName = name;
	return true;
}

School::School(){
	students = {NULL};
}

School::School(string name, Student* stdPtrList [3]){
	schoolName = name;
	for(int i = 0; i < 3; i++){
		students[i] = stdPtrList[i];
	} 
}
		
string School::getSchoolName(){
	return schoolName;
}
		
Student* School::getStudents(){
	return students;
}
		
bool School::setSchoolName(string name){
	if(name.length() == 0) return false;
	schoolName = name;
	return true;
}
		
void School::setStudents(Student arr[3], int studentListCount){
	for(int i = 0; i < studentListCount; i++){
		students[i] = arr[i];
	}
}

int main(){
	
	Student s1 = Student(1, "park");
	Student s2 = Student(2, "kim");
	Student s3 = Student(3, "lee");
	Student* students[3] = {&s1, &s2, &s3};

	cout << students[0]->getStudentName() << endl;
	
	int studentsSize = (int)(sizeof(students) / sizeof(students[0]));
	
	School school = School("sch1", students);
	
	for(int i=0; i < 3; i++){
		cout << "student number : " << students[i]->getStudentNumber() << endl;
		cout << "student name : " << students[i]->getStudentName() << endl;
	}
	
	return 0;
}

