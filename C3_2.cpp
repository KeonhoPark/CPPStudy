#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    int studentNumber;
    char* studentName;

public:
    Student(int number, const char* name) {
        studentNumber = number;
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);
    }

    // 추가된 기본 생성자
    Student() : studentNumber(0), studentName(nullptr) {}

    int getStudentNumber();
    char* getStudentName();
    bool setStudentNumber(int);
    bool setStudentName(const char*);

    ~Student() {
        delete[] studentName;
    }
};

int Student::getStudentNumber() {
    return studentNumber;
}

char* Student::getStudentName() {
    return studentName;
}

bool Student::setStudentNumber(int number) {
    if (number < 1) {
        return false;
    }
    studentNumber = number;
    return true;
}

bool Student::setStudentName(const char* name) {
    if (strlen(name) > 5) {
        return false;
    }
    strcpy(studentName, name);
    return true;
}

class School {
private:
    char* schoolName;
    Student students[3];

public:
    School(const char* name, Student arr[3], int studentListCount);
    char* getSchoolName();
    Student* getStudents();
    bool setSchoolName(const char* name);
    void setStudents(Student arr[3], int studentListCount);

    ~School() {
        delete[] schoolName;
    }
};

School::School(const char* name, Student arr[3], int studentListCount) {
    schoolName = new char[strlen(name) + 1];
    strcpy(schoolName, name);
    for (int i = 0; i < studentListCount; i++) {
        students[i] = arr[i];
    }
}

char* School::getSchoolName() {
    return schoolName;
}

Student* School::getStudents() {
    return students;
}

bool School::setSchoolName(const char* name) {
    if (strlen(name) == 0) return false;
    strcpy(schoolName, name);
    return true;
}

void School::setStudents(Student arr[3], int studentListCount) {
    for (int i = 0; i < studentListCount; i++) {
        students[i] = arr[i];
    }
}

int main() {
    Student s1 = Student(1, "park");
    Student s2 = Student(2, "kim");
    Student s3 = Student(3, "lee");

    Student students[3] = { s1, s2, s3 };
    int studentsSize = sizeof(students) / sizeof(students[0]);

    School school = School("sch1", students, studentsSize);
    Student* stdPtr = school.getStudents();

    for (int i = 0; i < studentsSize; i++) {
        cout << "student number: " << (stdPtr+i)->getStudentNumber() << endl;
        cout << "student name: " << (stdPtr+i)->getStudentName() << endl;
    }

    return 0;
}
