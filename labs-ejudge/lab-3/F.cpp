#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        a[i] = t;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
    int p;
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        int t;
        cin >> t;
        int l = 0, r = n - 1, m;
        int cnt1 = 0, cnt2 = 0;
        while (r >= l)
        {
            m = l + (r - l) / 2;
            if (a[r] <= t)
            {
                cnt1 = r + 1;
                break;
            }
            if (a[m] > t)
                r = m - 1;
            else if (a[m] <= t)
            {
                l = m + 1;
                cnt1 = m + 1;
            }
        }
        for (int i = 0; i < cnt1; i++)
        {
            cnt2 += a[i];
        }

        cout << cnt1 << " " << cnt2 << endl;
    }

    return 0;
}