#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include "student.h"

using namespace std;

class Search
{
private:
    Student *studentList;

public:
    Search(Student *studentList);
    void displayListAll(int listSize);
    void searchByName(int listSize);
    void searchByID(int listSize, int criteria);
    void searchByDept(int listSize);
    void displayCategory();
};

#endif