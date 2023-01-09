#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> p;
vector<vector<int>> g;


int g_l(int v)
{
    if (v == p[v])  return v;
    return p[v] = g_l(p[v]);
}

bool d_m(int a, int b)
{ 
    a = g_l(a);
    b = g_l(b);
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
   
    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> ans_com;

    int ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        ans_com.push_back(ans);
        ans++;
        for (int j = 0; j < g[i].size(); j++)
        {
            int mm = g[i][j];
            if (mm  > i)
            {
                if (d_m(i, mm))
                    ans--;
            }
        }
    }

    for (int i = ans_com.size() - 1; i >= 0; i--)  cout << ans_com[i] <<  "\n";
    
}