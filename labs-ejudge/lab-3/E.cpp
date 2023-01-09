#include <iostream>
#include <algorithm>
using namespace std;

bool check_inside(int x, int y, int square)
{
    return square >= x and square >= y;
}

int check(int a[], int b[], int size, int x)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (check_inside(a[i], b[i], x))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n], b[n];
    long long l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = x2;
        b[i] = y2;
        r = max(max(x2, y2), r);
    }
    int start_index = -1;
    while  (l <= r)
    {
        long long mid = l + (r - l) / 2;
        if (check(a, b, n, mid) == k)
        {
            start_index = mid;
            r = mid - 1;
        }
        else if (check(a, b, n, mid) > k)
        {
            r = mid - 1;
        }
        else
        {
         l = mid + 1;
        }
    }
    if (start_index == -1)
    {
        start_index = l;
    }
    cout << start_index;
}