#include <iostream>
#include <queue>
using namespace std;


vector<int> sortedVec, col;

vector<bool> was;
vector<vector<int>> g;

void topsort(int v)
{
    was[v] = true;
    for (int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if (!was[u])
        {
            topsort(u);
        }
    }
    sortedVec.push_back(v);
}

bool delCyc(int v)
{
    col[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if (col[u] == 1)
        {
            return true;
        }
        if (col[u] == 0)
        {
            if (delCyc(u))
                return true;
        }
    }
    col[v] = 2;
    return false;
}

int main()
{
    int m, n; cin >> m >> n;
    g.resize(m);
    col.resize(m);
    was.resize(m);

        for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u-=1;
        v-=1;
        g[u].push_back(v);
    }


    bool has_Cyc= false;
    for (int i = 0; i < m; i++)
    {
        if (delCyc(i))
        {
            has_Cyc= true;
            break;
        }
    }
    if (!has_Cyc)
    {
        cout << "Possible" << "\n";
        for (int i = 0; i < m; i++)
        {
            if (!was[i])
            
                topsort(i);
            
        }
        for (int i = sortedVec.size() - 1; i >= 0; i--)
        
            cout << sortedVec[i] + 1 << " ";
        
    }
    else
    
        cout << "Impossible";
    


}