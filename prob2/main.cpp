#include <iostream>
#include <fstream>
#include <algorithm>
#include <regex>
#include "student.h"
#include "search.h"
#include "sort.h"

using namespace std;

void displayInitPage();
void save(Student student);
Student insertStudentInfo();
int getNumOfLines();
Student *getStudentList(int numOfStudents);
void displayStudentInfo(Student *studentList, int listSize);
void sortStudents(Student *studentList, int listSize);
void nameValidation(string name);

enum
{
    INSERT = 1,
    SEARCH = 2,
    SORT = 3,
    EXIT = 4
};

int main()
{
    int choice;
    int lineCount;
    Student *studentList;

    ofstream fout("file1.txt", ios::app);

    while (1)
    {
        displayInitPage();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case INSERT:
            save(insertStudentInfo());
            break;
        case SEARCH:
            if (getNumOfLines() == 0)
            {
                cout << "There is no student information. Please input student information." << endl;
                break;
            }

            studentList = getStudentList(getNumOfLines());
            displayStudentInfo(studentList, getNumOfLines());
            break;
        case SORT:
            if (getNumOfLines() == 0)
            {
                cout << "There is no student information. Please input student information." << endl;
                break;
            }

            studentList = getStudentList(getNumOfLines());
            sortStudents(studentList, getNumOfLines());
            break;
        case EXIT:
            return 0;
        default:
            cout << "!!!Wrong selection!!!" << endl;
            cout << endl;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            break;
        }
    }
}

void displayInitPage()
{
    cout << "1. Insertion" << endl;
    cout << "2. Search" << endl;
    cout << "3. Sorting Option" << endl;
    cout << "4. Exit" << endl;
}

Student insertStudentInfo()
{
    string name;
    string ID;
    string birthYear;
    string dept;
    string tel;
    regex regName("[a-zA-Z]([a-zA-Z\\s])*([a-zA-Z])*");
    regex regID("[0-9]([0-9])*");
    Student *studentList;

    while (true)
    {
        cout << "Name ? ";
        getline(cin, name);

        if (name == "")
        {
            cout << "There is no input." << endl;
            continue;
        }

        if (name.size() > 15)
        {
            cout << "Your name is too long!!" << endl;
            continue;
        }

        if (!regex_match(name, regName))
        {
            cout << "Your input is wrong. Only use English." << endl;
            continue;
        }

        break;
    }

    while (true)
    {
        cout << "Student ID (10 digits) ? ";
        getline(cin, ID);

        if (ID.size() == 0)
        {
            cout << "There is no input." << endl;
            continue;
        }

        if (ID.size() != 10)
        {
            cout << "Your Student ID length must be 10." << endl;
            continue;
        }

        if (!regex_match(ID, regID))
        {
            cout << "Your input is wrong. Only use digits." << endl;
            continue;
        }

        studentList = getStudentList(getNumOfLines());

        for (int i = 0; i < getNumOfLines(); i++)
        {
            if (studentList[i].getID().find(ID) != string::npos)
            {
                cout << "Error : Already inserted" << endl;
                ID = "100";
                break;
            }
        }

        if (ID == "100")
        {
            continue;
        }

        break;
    }

    while (true)
    {
        cout << "Birth Year (4 digits) ? ";
        getline(cin, birthYear);

        if (birthYear.size() == 0)
        {
            birthYear = "~";
            break;
        }

        if (birthYear.size() != 4)
        {
            cout << "Your birth year length must be 10." << endl;
            continue;
        }

        if (!regex_match(birthYear, regID))
        {
            cout << "Your input is wrong. Only use digits." << endl;
            continue;
        }

        break;
    }

    while (true)
    {
        cout << "Department ? ";
        getline(cin, dept);

        if (dept.size() == 0)
        {
            dept = "~";
            break;
        }

        break;
    }

    while (true)
    {
        cout << "Tel ? ";
        getline(cin, tel);

        if (tel.size() == 0)
        {
            tel = "~";
            break;
        }

        if (tel.size() > 12)
        {
            cout << "Your telephone number is too long!!" << endl;
            continue;
        }

        if (!regex_match(tel, regID))
        {
            cout << "Your input is wrong. Only use digits." << endl;
            continue;
        }

        break;
    }
    cout << endl;

    return Student(name, ID, birthYear, dept, tel);
}

void save(Student student)
{
    ofstream fout("file1.txt", ios::app);
    fout << student.getName() << "," << student.getID() << "," << student.getBirthYear() << "," << student.getDept() << "," << student.getTel() << endl;
    fout.close();
}

int getNumOfLines()
{
    int lineCount = 0;
    int commaCount = 0;
    char c;

    ifstream fin("file1.txt");

    while (fin.get(c))
    {
        if (c == ',')
        {
            commaCount++;
            if (commaCount == 4)
            {
                lineCount++;
                commaCount = 0;
            }
        }
    }

    fin.close();

    return lineCount;
}

Student *getStudentList(int numOfStudents)
{
    Student *studentList = new Student[numOfStudents];
    char line[1000001];
    int i = 0;

    ifstream fin("file1.txt");

    while (fin.getline(line, sizeof(line)))
    {
        studentList[i].setName(strtok(line, ","));
        studentList[i].setID(strtok(NULL, ","));
        studentList[i].setBirthYear(strtok(NULL, ","));
        studentList[i].setDept(strtok(NULL, ","));
        studentList[i].setTel(strtok(NULL, ","));
        i++;
    }

    fin.close();

    return studentList;
}

void displayStudentInfo(Student *studentList, int listSize)
{
    Search search(studentList);
    int choice;

    cout << endl;
    cout << "- Search -" << endl;
    cout << "1. Search by name" << endl;
    cout << "2. Search by student ID (10 numbers)" << endl;
    cout << "3. Search by admission year (4 numbers)" << endl;
    cout << "4. Search by department name" << endl;
    cout << "5. List All" << endl;

    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
        search.searchByName(listSize);
        break;
    case 2:
        search.searchByID(listSize, 2);
        break;
    case 3:
        search.searchByID(listSize, 3);
        break;
    case 4:
        search.searchByDept(listSize);
        break;
    case 5:
        search.displayListAll(listSize);
        break;
    default:
        cout << "!!!Wrong selection!!!" << endl;
        break;
    }
}

void sortStudents(Student *studentList, int listSize)
{
    Sort sort(studentList);

    int choice;

    cout << endl;
    cout << "- Sorting Option -" << endl;
    cout << "1. Sort by name" << endl;
    cout << "2. Sort by student ID" << endl;
    cout << "3. Sort by admission year" << endl;
    cout << "4. Sort by department name" << endl;

    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
        sort.sortByName(listSize);
        break;
    case 2:
        sort.sortByID(listSize);
        break;
    case 3:
        sort.sortByID(listSize);
        break;
    case 4:
        sort.sortByDept(listSize);
        break;
    default:
        cout << "!!!Wrong selection!!!" << endl;
        break;
    }

    cout << endl;
}