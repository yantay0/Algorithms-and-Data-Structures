#include <iostream>
#include <cmath>
#include <algorithm>
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

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int bin_ser(int a[], int n, int target)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == target)
            return a[mid];
        if (a[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    int min = INT32_MAX;
    for (int i = 1; i < n; i++)
    {
        if (abs(a[i] - a[i - 1]) < min)
        {
            min = abs(a[i] - a[i - 1]);
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (abs(a[i + 1] - a[i]) == min)
        {
            cout << a[i] << " " << a[i + 1] << " ";
        }
        // cout << a[i] << " ";
    }
    return 0;
}