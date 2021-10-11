#ifndef SORT_H
#define SORT_H

#include <iostream>
#include "student.h"

using namespace std;

class Sort
{
private:
    Student *studentList;

public:
    Sort(Student *studentList);
    void sortByName(int listSize);
    void sortByID(int listSize);
    void sortByDept(int listSize);
};

bool compareByName(Student x, Student y);
bool compareByID(Student x, Student y);
bool compareByDept(Student x, Student y);

#endif