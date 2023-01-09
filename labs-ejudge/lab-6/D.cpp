#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct date
{
    int d;
    int m;
    int y;
    void push(string s)
    {
        // int d,m,y;
        string date = "";
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            date += s[i];
            if (s[i] == '-' or i == s.size() - 1)
            {
                cnt++;
                if (cnt == 1)
                    d = stoi(date);
                if (cnt == 2)
                    m = stoi(date);
                if (cnt == 3)
                    y = stoi(date);
                date = "";
            }
        }
    }
};
bool compare(const date &d1, const date &d2)
{
    // All cases when true should be returned
    if (d1.y < d2.y)
        return true;
    if (d1.y == d2.y && d1.m < d2.m)
        return true;
    if (d1.y == d2.y && d1.m == d2.m &&
        d1.d < d2.d)
        return true;

    // If none of the above cases satisfy, return false
    return false;
}

void sortDates(date arr[], int n)
{
    sort(arr, arr + n, compare);
}

int partition(date arr[], int low, int high)
{
    int pivot = high;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (compare(arr[j],arr[pivot]))
        {
            i++;
            swap(arr[i], arr[j]); // что за х
        }
    }

    swap(arr[i + 1], arr[pivot]);
    return i + 1;
}

void quickSort(date arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    // string date = "";
    int n;
    cin >> n;
    date arr[n];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        arr[i].push(s);
    }
    sortDates(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%02d-", arr[i].d);
        printf("%02d-", arr[i].m);
        printf("%d", arr[i].y);
        cout << endl;
    }
}