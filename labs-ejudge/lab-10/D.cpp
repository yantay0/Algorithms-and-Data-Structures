#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[6000];
bool was[6000];
int d[6000];
int color[6000];
int n;
void BFS(int s)
{
    for (int i = 1; i <= n; i++)
    {

        was[i] = 0;
    }
    queue<int> q;
    q.push(s);
    d[s] = 0;
    was[s] = 1;
    while (!q.empty())
    {
        int m = q.front();
        q.pop();
        for (int i = 0; i < v[m].size(); i++)
        {
            int to = v[m][i];
            if (d[to] > d[m] + 1)
            {
                d[to] = d[m] + 1;
                was[to] = 1;
                q.push(to);
            }
        }
    }
}

int main()
{
    int m, q;  cin >> n >> m >> q;
    for (int i = 0; i < m; i++)
    {
        int u, m;
        cin >> u >> m;
        v[u].push_back(m);
        v[m].push_back(u);
    }


    for (int i = 1; i <= n; i++)
    {
        d[i] = 1e9;
    }
    for (int j = 1; j <= q; j++)
    {
        int t, m;
        cin >> t >> m;
        if (t == 1)
        {
            if (color[m] != 1)
            {
                BFS(m);
                color[m] = 1;
            }
        }


        else
        {
            if (d[m] != 1e9)
            {
                cout << d[m] << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
}
