#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
stack<int> st;
int was[600];
vector<int> v1;
vector<int> gg[600];

bool dfs_2(int v)
{
    was[v] = 1;

    
    st.push(v);
    for (int i = 0; i < gg[v].size(); i++)
    {
        int to = gg[v][i];
        if (!was[to])
        {
            if (dfs_2(to))
                return true;
        }
        else if (was[to] == 1)
        {
            while (st.top() != to)
            {
                v1.push_back(st.top());
                st.pop();
            }
            v1.push_back(to);
            v1.push_back(v);
            reverse(v1.begin(), v1.end());
            return true;
        }
    }
    was[v] = 2;
    if (!st.empty())
        st.pop();
    return false;
}

bool dfs(int v, int a, int b)
{
    was[v] = 1;
    for (int i = 0; i < gg[v].size(); i++)
    {
        int to = gg[v][i];
        if (v == a && b == to)
            continue;
        if (!was[to])
        {
            if (dfs(to, a, b))
                return true;
        }
        else if (was[to] == 1)
        {
            return true;
        }
    }
    was[v] = 2;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        gg[u].push_back(v);
    }

    bool c = false;
    for (int i = 1; i <= n; i++)
    {
        if (!was[i])
        {
            c = dfs_2(i);
            if (c)
                break;
        }
    }

    if (!c)
    {
        cout << "YES" << endl;
        return 0;
    }

    for (int i = 0; i < v1.size() - 1; i++)
    {
        int u = v1[i];
        int v = v1[i + 1];
        for (int j = 1; j <= n; j++)
        {
            was[j] = 0;
        }
        c = 0;

        for (int j = 1; j <= n; j++)
        {
            if (!was[j])
            {
                c |= dfs(j, u, v);
            }
        }

        
        if (!c)
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}