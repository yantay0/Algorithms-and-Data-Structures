#include <bits/stdc++.h>
using namespace std;

int c[200005];
int p[200005];

int main()
{
    int n, m;
    cin >> n >> m;
    int  a, b, cnt = 0;

    for (int i = 1; i <=m; i++)
    {
        cin >> a >> b;
        p[b] = a;
        c[a]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (c[p[i]] == 0)
        
            cnt++;
        
        else if (c[p[i]] < c[i])
        
            cnt++;
        
    }

    cout << cnt << "\n";
}