#include <iostream>
using namespace std;

int bin_seach_inc(int a[], int target, int n)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left);
        if (a[mid] == target)
        {
            return mid;
        }
        if (a[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int bin_search_dec(int a[], int target, int n)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left);
        if (a[mid] == target)
        {
            return mid;
        }
        if (a[mid] > target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int b[n];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int row, col;
    cin >> row >> col;
    int a[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (j % 2 == 0)
            {
                index = bin_search_dec(a[j], b[i], col);
                if (index != -1)
                {
                    cout << j << " " << index << endl;
                    break;
                }
                else if (index == -1 and j == row - 1)
                {
                    cout << index << endl;
                    break;
                }
            }
            else if (j % 2 != 0)
            {
                index = bin_seach_inc(a[j], b[i], col);
                if (index != -1)
                {
                    cout << j << " " << index << endl;
                    break;
                }
                else if (index == -1 and j == row - 1)
                {
                    cout << index << endl;
                    break;
                }
            }
        }
    }
}