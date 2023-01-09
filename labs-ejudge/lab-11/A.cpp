#include <bits/stdc++.h>
using namespace std;
#define ul unsigned long long

vector<pair<ul, pair<ul, ul>>> g;
vector<ul> p;

int get_lider(ul v)
{
    if (v == p[v])
        return v;
    p[v] = get_lider(p[v]);
}

void dsu_merge(ul u, ul v)
{
    u = get_lider(u);
    v = get_lider(v);

    if (u != v)
        p[u] = v;
}

int main()
{
    ul res = 0;
    ul n, q;
    cin >> n >> q;
    p.resize(n);
    g.resize(n);

    for (int i = 0; i < q; i++)
    {
        ul a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g.push_back(make_pair(c, make_pair(a, b)));
    }
    for (int i = 0; i < n; i++)
        p[i] = i;

    sort(g.begin(), g.end());

    
    for (ul i = 0; i < g.size(); i++)
    {
        ul a = g[i].second.first;
        ul b = g[i].second.second;
        ul c = g[i].first;

        for (ul j = a + 1; j <= b; j++)
        {
            if (get_lider(a) != get_lider(j))
            {
                res += c;
                dsu_merge(a, j);
            }
            else

                j = p[a];
        }
    }
    cout << res << endl;
}