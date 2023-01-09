#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int, pair<int, int>>> h;
vector <int> g;

int dsg(int a)
{
    if (a == g[a])
    {
        return a;
    }
    else
    {
        return g[a] = dsg(g[a]);
    }
}

void dsu_merge(int a, int b)
{
    a = dsg(a);
    b = dsg(b);
    if (a != b)
    {
        g[a] = b;
    }
}

int main()
{

    int l, r, v, w;
    int totalCost = 0;
    string type;

    cin >> l >> r >> v >> w;
    g.resize(l);
    int mad = min(v, w);
    for (int i = 0; i < r; i++)
    {

        int a, b, c;
        cin >> type >> a >> b >> c;
        a--;
        b--;
        if (type == "small") c = c * w;
    
        else if (type == "big") c = c * v;
        
        else c = c * mad;
        
        h.push_back({c, {a, b}});
    }

    sort(h.begin(), h.end());

    for (int i = 0; i < l; ++i)
        g[i] = i;

    for (int i = 0; i < h.size(); ++i)
    {
        int a = h[i].second.first;
        int b = h[i].second.second;
        int cost = h[i].first;
        if (dsg(a) != dsg(b))
        {
            totalCost += cost;
            dsu_merge(a, b);
        }
    }

    cout << totalCost;

    return 0;
}