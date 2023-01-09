#include <iostream>
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

void printSolve(int arr[], int size)
{
    string ans = "";
    for (int i = 0; i < size; i++)
      ans+=arr[i] + '0';

    cout << ans;
}

int main()
{
    string s; cin >> s;
    int n = s.size();
    int a[n];
    int i = 0;
    while(i!=n){
        a[i]=s[i]-48;
        i++;
    }

    quickSort(a,0,n-1);
    printSolve(a,n);
   
   
    return 0;
}
