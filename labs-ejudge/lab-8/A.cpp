#include <iostream>
#include <map>
#include <vector>
using namespace std;

long long MOD = 1e9 + 7;
long long X = 11;

long long getHash(string s)
{
    long long hash = 0;
    long long curX = 1;

    for (int i = 0; i < s.size(); i++)
    {
        long long curHash = (s[i] - 47) * curX % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X) % MOD;
    }
    return hash;
}

int main()
{
    int n;
    cin >> n;
    map<string, int> m;
    vector<string> v;
    int k = n * 2;
    int cnt = 0;
    // vector <string> v;
    while (k--)
    {
        string s;
        cin >> s;
        m[s]++;
        // m[to_string(getHash(s))]++;
        v.push_back(s);
    }

    for (int i = 0; i < v.size(); i++)
    {
        string h = to_string(getHash(v[i]));
        // m[h]++;
        if (m.find(h) != m.end())
        {
            cout << "Hash of string " << '"' << v[i] << '"' << " "
                 << "is " << h << endl;
            cnt++;
            if (cnt == n)
                break;
        }
    }
}