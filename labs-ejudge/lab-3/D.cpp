#include <iostream>
#include <algorithm>
using namespace std;
int f_left(int a[], long long size, int x)
{
    int startindex = -1;
    long long left = 0, right = size - 1;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (a[mid] == x)
        {
            startindex = mid;
            right = mid - 1;
        }
        else if (a[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (startindex == -1)
    {
        return left;
    }
    return startindex;
}

int f_right(int a[], long long size, int x)
{
    int endindex = -1;
    long long left = 0, right = size - 1;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (a[mid] == x)
        {
            endindex = mid;
            left = mid + 1;
        }
        else if (a[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (endindex == -1)
    {
        return right;
    }
    return endindex;
}

int count(int a[], long long size, long long left, long long right)
{
    return f_right(a, size, right) - f_left(a, size, left) + 1;
}

int main()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    for (int i = 0; i < q; i++)
    {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (l1 <= l2)
        {
            if (r1 < l2)
            {
                
                cout << count(a, n, l1, r2) - count(a, n, r1 + 1, l2 - 1) << endl;
            }
            else
            {
                cout << count(a, n, l1, max(r1, r2)) << endl;
            }
        }
        else
        {
            if (r2 < l1)
            {
                cout << count(a, n, l2, r1) - count(a, n, r2 + 1, l1 - 1) << endl;
            }
            else
            {
                cout << count(a, n, l2, max(r1, r2)) << endl;
            }
        }
    }
}