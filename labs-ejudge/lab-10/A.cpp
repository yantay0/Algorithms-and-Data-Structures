#include <bits/stdc++.h>
using namespace std;

int m,n;

int solve(vector<vector<int>> &grids)
{
    int m = grids.size();
    int n = grids[0].size();

    int ans = 0, t = -1;

    vector<pair<int, int>> ks = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grids[i][j] == 1)
                ans++;
            else if (grids[i][j] == 2)
                q.push({i, j});
        }
    }

    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            pair<int, int> cur = q.front();
            q.pop();
            for (auto k : ks)
            {
                int x = cur.first + k.first;
                int y = cur.second + k.second;
                if (x >= 0 && x < m && y >= 0 && y < n && grids[x][y] == 1)
                {
                    grids[x][y] = 2;
                    q.push({x, y});
                    ans--;
                }
            }
        }
        t++;
    }
    if (ans > 0)
        return -1;
    if (t == -1)
        return 0;
    return t;
}

int main()
{
    cin >> n >> m;


    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }


    cout << solve(v) << endl;
}