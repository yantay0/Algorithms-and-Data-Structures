
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string s1, string s2)
{
    if (s1.size() <= s2.size())
        return true;
    return false;
}
void mergeSortedIntervals(vector<string> &v, int s, int m, int e)
{

    vector<string> temp;

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

void mergeSort(vector<string> &v, int s, int e)
{
    if (s < e)
    {
        int m = (s + e) / 2;
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        mergeSortedIntervals(v, s, m, e);
    }
}

void printArray(vector<string> v, int size)
{
    for (int i = 0; i < size; i++)
        cout << v[i] << " ";
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vector<string> v;
        int k = 0;
        while (true)
        {

            string s;
            cin >> s;
            v.push_back(s);
            if (cin.peek() == '\n')
                break;
        }
        mergeSort(v, 0, v.size() - 1);
        printArray(v, v.size());
        cout << endl;
    }
}