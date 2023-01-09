#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;


    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        
            cin >> arr[i][j];
        
    }

    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x=x-1;
        y=y-1;
        z=z-1;
        if (arr[x][y] == 1  && arr[y][x] == 1 &&  arr[z][x] == 1 && arr[x][z] == 1 &&  arr[y][z] == 1 &&  arr[z][y] == 1)
        
            cout << "YES";
        
        else
       
            cout << "NO";
        cout << endl;
        
    }
   
}