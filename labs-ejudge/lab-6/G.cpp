#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
string printSolve(int arr[], int size)
{
    string ans = "";

    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
            ans += arr[i] + '0';
    }
    return ans;
}

int *fill(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    map<string, string> mp;

    while (n--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        mp[s1] = s2;
        if (!mp.empty())
        {
            for (auto i : mp)
            {

                if (i.second == s1)
                {
                    mp[i.first] = s2;
                    mp.erase(s1);
                    break;
                }
            }
        }
    }
    cout << mp.size() << endl;
    for (auto i : mp)
    {
        cout << i.first << " " << i.second << endl;
    }
}