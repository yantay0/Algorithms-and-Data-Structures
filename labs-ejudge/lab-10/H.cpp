#include <iostream>
using namespace std;

int n, m, cnt;

void dfs(char **c, int i, int j)
{
    if (i < 0 or i == n or j < 0 or j == m or c[i][j] == '0')
        return;
    c[i][j] = '0';
    dfs(c, i + 1, j);
    dfs(c, i - 1, j);
    dfs(c, i, j + 1);
    dfs(c, i, j - 1);
}

int main()
{

    cin >> n >> m;
    char **c = new char *[n];
    for (int i = 0; i < n; i++)
    {
        c[i] = new char[m];
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (c[i][j] == '1')
            {
                dfs(c, i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
}