#include <iostream>
using namespace std;
int cnt;
int bin_ser(int b[], int target, int n)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        cnt++;
        int mid = left + (right - left) / 2;
        cout << b[mid] << " " ;
        if (target <= b[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}
int main()
{
    int n, m, sum = 0;
    cin >> n;
    //  >> m;
    int b[n];
    for (int i = 0; i < n; i++)
    {
        // int x;
        // cin >> x;
        cin >> b[i];
        // sum += x;
        // b[i] = sum;
    }
    bin_ser(b,26,15);
    // cout << cnt ;
    // while (m--)
    // {
    //     int target;
    //     cin >> target;
    //     cout << bin_ser(b, target, n) + 1 << endl;
    // }
}