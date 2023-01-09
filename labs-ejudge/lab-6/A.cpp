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
string printSolve(int arr[], int size)
{
    string ans = "";

    for (int i = 0; i < size; i++)
    {
        if(arr[i]!=0)
        ans+=arr[i]+'0';
    }
    return ans;
}

int * fill(int a[], int n){
    for(int i = 0; i < n ;i++){
        a[i]=0;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    string s; cin >> s;
    int v[n],c[n];
    fill(v,n);
    fill(c,n);
    int j = 0;
    int k = 0;
    for(int i = 0 ; i < s.size(); i++){
        if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
        {
           v[j] = s[i] - 48;
           j++;
        }
        else {
            c[k]= s[i]- 48;
            k++;
        }
    }

    quickSort(v, 0, n-1);
    quickSort(c, 0, n-1);
    cout << printSolve(v,n)+printSolve(c,n);
    return 0;
}
