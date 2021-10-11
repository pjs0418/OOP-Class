#include <iostream>
#include "student.h"

using namespace std;

Student::Student() : name(""), ID(""), birthYear(""), dept(""), tel("") {}

Student::Student(string name, string ID, string birthYear, string dept, string tel) : name(name), ID(ID), birthYear(birthYear), dept(dept), tel(tel) {}

string Student::getName()
{
    return name;
}

string Student::getID()
{
    return ID;
}

string Student::getBirthYear()
{
    return birthYear;
}

string Student::getDept()
{
    return dept;
}

string Student::getTel()
{
    return tel;
}

void Student::setName(string name)
{
    this->name = name;
}

void Student::setID(string ID)
{
    this->ID = ID;
}

void Student::setBirthYear(string birthYear)
{
    this->birthYear = birthYear;
}

void Student::setDept(string dept)
{
    this->dept = dept;
}

void Student::setTel(string tel)
{
    this->tel = tel;
}

bool Student::compareByName(Student x, Student y)
{
    return x.getName() < y.getName();
}