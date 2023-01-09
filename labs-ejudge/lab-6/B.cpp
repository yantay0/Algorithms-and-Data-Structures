#include <iostream>
#include <map>
#include <vector>
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

    quickSort(a, 0, n - 1);
    quickSort(b, 0, m - 1);
    vector <int> ans;
    int i = 0, j = 0 , k = -1;

    while(i < n && j < m){
        if(a[i]==b[j]){
           
                ans.push_back(a[i]);
                
                i++;
                j++;
        }
        else if (a[i] < b[j]){
            i++;
        }
        else {
            j++;
        }
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}