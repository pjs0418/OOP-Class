#include <iostream>
#include <algorithm>
#include "search.h"

using namespace std;

Search::Search(Student *studentList) : studentList(studentList) {}

void Search::displayListAll(int listSize)
{
    cout << endl;
    displayCategory();

    for (int i = 0; i < listSize; i++)
    {
        cout << studentList[i].getName() << " " << studentList[i].getID() << " " << studentList[i].getBirthYear() << " " << studentList[i].getDept() << " " << studentList[i].getTel() << endl;
    }

    cout << endl;
}

void Search::searchByName(int listSize)
{
    string searchInput;
    string searchTarget;
    cout << "Student name keyword? ";
    getline(cin, searchInput);

    if (searchInput == "")
    {
        cout << endl;
        cout << "There is no input." << endl;
        cout << endl;
        return;
    }

    transform(searchInput.begin(), searchInput.end(), searchInput.begin(), ::toupper);

    cout << endl;

    displayCategory();

    for (int i = 0; i < listSize; i++)
    {
        searchTarget = studentList[i].getName();
        transform(searchTarget.begin(), searchTarget.end(), searchTarget.begin(), ::toupper);

        if (searchTarget.find(searchInput) != string::npos)
        {
            cout << studentList[i].getName() << " " << studentList[i].getID() << " " << studentList[i].getBirthYear() << " " << studentList[i].getDept() << " " << studentList[i].getTel() << endl;
        }
    }

    cout << endl;
}

void Search::searchByID(int listSize, int criteria)
{
    string searchInput;
    if (criteria == 2)
    {
        cout << "Student ID keyword? ";
    }
    else
    {
        cout << "Admission year keyword? ";
    }
    getline(cin, searchInput);

    if (searchInput == "")
    {
        cout << endl;
        cout << "There is no input." << endl;
        cout << endl;
        return;
    }

    cout << endl;
    displayCategory();

    for (int i = 0; i < listSize; i++)
    {
        if (studentList[i].getID().find(searchInput) != string::npos)
        {
            cout << studentList[i].getName() << " " << studentList[i].getID() << " " << studentList[i].getBirthYear() << " " << studentList[i].getDept() << " " << studentList[i].getTel() << endl;
        }
    }

    cout << endl;
}

void Search::searchByDept(int listSize)
{
    string searchInput;
    string searchTarget;
    cout << "Department name keyword? ";
    getline(cin, searchInput);

    if (searchInput.size() == 0)
    {
        cout << endl;
        cout << "There is no input." << endl;
        cout << endl;
        return;
    }

    transform(searchInput.begin(), searchInput.end(), searchInput.begin(), ::toupper);

    cout << endl;
    displayCategory();

    for (int i = 0; i < listSize; i++)
    {
        searchTarget = studentList[i].getDept();
        transform(searchTarget.begin(), searchTarget.end(), searchTarget.begin(), ::toupper);

        if (searchTarget.find(searchInput) != string::npos)
        {
            cout << studentList[i].getName() << " " << studentList[i].getID() << " " << studentList[i].getBirthYear() << " " << studentList[i].getDept() << " " << studentList[i].getTel() << endl;
        }
    }

    cout << endl;
}

void Search::displayCategory()
{
    cout << "Name "
         << "StudentID "
         << "Birth Year "
         << "Dept "
         << "Tel" << endl;
}