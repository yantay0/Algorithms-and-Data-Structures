#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> p;

int getLider(int v)
{
    if (v == p[v])
        return v;
    return p[v] = getLider(p[v]);
}

bool dsu_merge(int a, int b)
{ // в разных ли комп
    a = getLider(a);
    b = getLider(b);
    if (a != b)
    {
        p[a] = b;
        return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    p.resize(n);
    vector<int> cnt_components;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }

    int cnt = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        cnt_components.push_back(cnt);
        cnt++;
        for (int j = 0; j < g[i].size(); j++)
        {
            int to = g[i][j];
            if (i < to)
            {
                if (dsu_merge(i, to))
                    cnt--;
            }
        }
    }

    for (int i = cnt_components.size() - 1; i >= 0; i--)
    {
        cout << cnt_components[i] << endl;
    }
}