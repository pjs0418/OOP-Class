#include <iostream>
#include <algorithm>
#include <fstream>
#include "sort.h"

using namespace std;

Sort::Sort(Student *studentList) : studentList(studentList) {}

void Sort::sortByName(int listSize)
{
    remove("file1.txt");

    sort(studentList, studentList + listSize, compareByName);

    ofstream fout("file1.txt", ios::app);

    for (int i = 0; i < listSize; i++)
    {
        fout << studentList[i].getName() << "," << studentList[i].getID() << "," << studentList[i].getBirthYear() << "," << studentList[i].getDept() << "," << studentList[i].getTel() << endl;
    }

    fout.close();
}

void Sort::sortByID(int listSize)
{
    remove("file1.txt");

    sort(studentList, studentList + listSize, compareByID);

    ofstream fout("file1.txt", ios::app);

    for (int i = 0; i < listSize; i++)
    {
        fout << studentList[i].getName() << "," << studentList[i].getID() << "," << studentList[i].getBirthYear() << "," << studentList[i].getDept() << "," << studentList[i].getTel() << endl;
    }

    fout.close();
}

void Sort::sortByDept(int listSize)
{
    remove("file1.txt");

    sort(studentList, studentList + listSize, compareByDept);

    ofstream fout("file1.txt", ios::app);

    for (int i = 0; i < listSize; i++)
    {
        fout << studentList[i].getName() << "," << studentList[i].getID() << "," << studentList[i].getBirthYear() << "," << studentList[i].getDept() << "," << studentList[i].getTel() << endl;
    }

    fout.close();
}

bool compareByName(Student x, Student y)
{
    string nameX = x.getName();
    string nameY = y.getName();

    transform(nameX.begin(), nameX.end(), nameX.begin(), ::toupper);
    transform(nameY.begin(), nameY.end(), nameY.begin(), ::toupper);

    return nameX < nameY;
}

bool compareByID(Student x, Student y)
{
    return x.getID() < y.getID();
}

bool compareByDept(Student x, Student y)
{
    string deptX = x.getDept();
    string deptY = y.getDept();

    transform(deptX.begin(), deptX.end(), deptX.begin(), ::toupper);
    transform(deptY.begin(), deptY.end(), deptY.begin(), ::toupper);

    return deptX < deptY;
}