#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<long long> was;
vector<long long> p;

int main()
{
    long long n, k;
    cin >> n >> k;
    p.resize(2000000);
    was.resize(2000000);
    vector<long long> res;
    queue<long long> q;
    q.push(n);


    was[n] = true;

    if (n == k)
    {
        cout << 0;
        return 0;
    }
    if (n > k)
    {
        cout << n - k << endl;
        n -= 1;
        while (n != k)
        {
            cout << n << " ";
            n--;
        }
        cout << k;
        return 0;
    }

    while (!q.empty())
    {
        unsigned long long v = q.front();
        q.pop();

        if (!was[2 * v] && v < k)
        {

            q.push(2 * v);
            was[2 * v] = true;
            p[2 * v] = v;
            if (2 * v == k)
                break;
        }
        if (v - 1 > 0 && !was[v - 1])
        {

            q.push(v - 1);
            was[v - 1] = true;
            p[v - 1] = v;
            if (v - 1 == k)
                break;
        }
    }
   long long f = k, s = n;
    while (f != s)
    {
        res.push_back(f);
        f = p[f];
    }


    cout << res.size() << '\n';

    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i] << " ";
    }


}