#include <iostream>
#include <map>
#include <vector>
using namespace std;

void mergeSortedIntervals(int v[], int s, int m, int e)
{

    vector<int> temp;

    int i, j;
    i = s;
    j = m + 1;

    while (i <= m && j <= e)
    {

        if (v[i] > v[j])
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

void mergeSort(int v[], int s, int e)
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
    int n;
    cin >> n;
    int m;
    cin >> m;

    int a[n], b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    mergeSort(a, 0, n - 1);
    mergeSort(b, 0, m - 1);
    vector<int> ans;
    int i = 0, j = 0, k = -1;

    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {

            ans.push_back(a[i]);

            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}