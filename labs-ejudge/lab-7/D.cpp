#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
struct course
{
    string grade;
    int credits;
    double mark;
    course(string grade, int credits)
    {
        mark = to_mark(grade);
        this->credits = credits;
    }
    double to_mark(string grade)
    {
        double mark;
        if (grade == "A+")
        {
            mark = 4.00;
        }
        if (grade == "A")
        {
            mark = 3.75;
        }
        if (grade == "B+")
        {
            mark = 3.5;
        }
        if (grade == "B")
        {
            mark = 3.00;
        }
        if (grade == "C+")
        {
            mark = 2.50;
        }
        if (grade == "C")
        {
            mark = 2.00;
        }
        if (grade == "D+")
        {
            mark = 1.50;
        }
        if (grade == "D")
        {
            mark = 1.00;
        }
        else if (grade == "F")
        {
            mark = 0;
        }
        return mark;
    }
};

struct student
{
    string lName;
    string fName;
    // course course;
    double avg;
    // course a[];
    vector<course> grades;
    student()
    {
    }

    student(string lName, string fName, vector<course> grades)
    {
        this->lName = lName;
        this->fName = fName;
        this->grades = grades;
        avg = average(grades);
    }

    double average(vector<course> grades)
    {
        double avg = 0.0;
        double sum = 0.0;
        int cr = 0;
        for (int i = 0; i < grades.size(); i++)
        {
            double mul = grades[i].mark * grades[i].credits;
            sum += mul;
            cr += grades[i].credits;
            mul = 0;
        }
        return sum / cr;
    }
    void print()
    {
        cout << lName << " " << fName << " " << fixed << setprecision(3) << avg;
    }
};
bool compare(const student &s1, const student &s2)
{
    if (s1.avg < s2.avg)
        return true;
    if (s1.avg == s2.avg && s1.lName < s2.lName)
        return true;
    if (s1.avg == s2.avg && s1.lName == s2.lName && s1.fName < s2.fName)
        return true;

    return false;
}

void mergeSortedIntervals(vector <student> &v, int s, int m, int e)
{

    vector<student> temp;

    int i, j;
    i = s;
    j = m + 1;

    while (i <= m && j <= e)
    {

        if (compare(v[i], v[j]))
        {
            temp.push_back(v[i]);
            ++i;
        }
        else
        {
            temp.push_back(v[j]);
            ++j;
        }
    }

    while (i <= m)
    {
        temp.push_back(v[i]);
        ++i;
    }

    while (j <= e)
    {
        temp.push_back(v[j]);
        ++j;
    }

    for (int i = s; i <= e; ++i)
        v[i] = temp[i - s];
}

void mergeSort(vector <student> &v, int s, int e)
{
    if (s < e)
    {
        int m = (s + e) / 2;
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        mergeSortedIntervals(v, s, m, e);
    }
}

int main()
{

    vector<course> v;
    int n;
    cin >> n;
    vector<student> students;

    while (n--)
    {
        string last_name, first_name;
        cin >> last_name >> first_name;
        int subject;
        cin >> subject;
        while (subject--)
        {
            string g;
            int c;
            cin >> g >> c;
            course *cou = new course(g, c);
            v.push_back(*cou);
        }
        student *s = new student(last_name, first_name, v);
        students.push_back(*s);
        v.clear();
    }
    mergeSort(students, 0, students.size() - 1);

    for (int i = 0; i < students.size(); i++)
    {
        students[i].print();
        cout << endl;
    }
}