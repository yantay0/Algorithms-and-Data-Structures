#include <iostream>

using namespace std;

int child[100005];
int parent[100005];

int main()
{
    int m, n, a, b, happy = 0;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        parent[b] = a;
        child[a]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (child[parent[i]] == 0)
        {
            happy++;
        }
        else if (child[parent[i]] < child[i])
        {
            happy++;
        }
    }

    cout << happy;
}