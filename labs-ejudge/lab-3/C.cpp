#include <iostream>
using namespace std;

bool bin_ser(int left,int right,int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if(target == mid)return true;
        if (target < mid)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return false;
}
int main()
{
    int n, m, sum = 0;
    cin >> n >> m;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }


    int cnt = 0;
    while (m--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        for (int i = 0; i < n; i++)
        {
            if (bin_ser(l1, r1, a[i]) or bin_ser(l2, r2, a[i]))cnt++;
       } 
       cout << cnt << endl;
       cnt = 0;
    
    }
}