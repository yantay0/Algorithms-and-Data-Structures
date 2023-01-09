#include <iostream>
#include <vector>
#include <set>
using namespace std;

long long MOD = 1e15 + 7;
long long X = 47;

long long getHash(string s)
{
    long long hash = 0;
    long long curX = 1;

    for (int i = 0; i < s.size(); i++)
    {
        long long curHash = (s[i] - 'a' + 1) * curX % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X) % MOD;
    }
    return hash;
}

vector<long long> getPrefixHashes(string s)
{
    vector<long long> hashes(s.size());
    long long curX = 1;
    for (int i = 0; i < s.size(); i++)
    {
        hashes[i] = (s[i] - 'a' + 1) * curX % MOD;
        if (i != 0)
        {
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        curX = (curX * X) % MOD;
    }
    return hashes;
}

vector<int> rabinKarp(string s, string t)
{
    long long smallHash = getHash(t);
    vector<int> res;
    vector<long long> hashes = getPrefixHashes(s);
    for (int i = 0; i < s.size() - t.size() + 1; i++)
    {
        long long hashDif = hashes[i + t.size() - 1];
        if (i != 0)
            hashDif -= hashes[i - 1];
        if (hashDif < 0)
            hashDif += MOD;
        if (i != 0)
            smallHash = (smallHash * X) % MOD;
        if (smallHash == hashDif)
        {
            res.push_back(i);
        };
    }
    return res;
}

int main()
{

    string text;
    cin >> text;
    set<int> cover;

    int n;
    cin >> n;

    while (n--)
    {
        string p;
        cin >> p;
        vector<int> v = rabinKarp(text, p);
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < p.size(); j++)
            {
                cover.insert(v[i] + j);
            }
        }
    }
    cover.size() == text.size() ? cout << "YES" : cout << "NO";
}