#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ggg;
vector<bool> was;
bool bith;
int m, n, x, y;

void DFS(int v)
{
    if (v == y)
    {
        bith = true;
        return;
    }
    was[v] = true;
    for (int i = 0; i < ggg[v].size(); i++)
    {
        int c = ggg[v][i];
        if (!was[c])
        {
            DFS(c);
        }
    }
}

int main()
{
    cin >> m >> n;
    was.resize(m);
    ggg.resize(m);

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        ggg[u].push_back(v);
        ggg[v].push_back(u);
    }
    cin >> x >> y;
    x -= 1;
    y -= 1;
    DFS(x);
    if (!bith)
        cout << "NO";
    else
        cout << "YES";
}