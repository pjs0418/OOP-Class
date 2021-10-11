#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student
{
private:
    string name;
    string ID;
    string birthYear;
    string dept;
    string tel;

public:
    Student();
    Student(string name, string ID, string birthYear, string dept, string tel);
    string getName();
    string getID();
    string getBirthYear();
    string getDept();
    string getTel();
    void setName(string name);
    void setID(string ID);
    void setBirthYear(string birthYear);
    void setDept(string dept);
    void setTel(string tel);
    bool compareByName(Student x, Student y);
};

#endif