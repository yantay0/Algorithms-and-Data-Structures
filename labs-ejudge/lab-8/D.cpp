#include <iostream>
#include <vector>
using namespace std;

long long MOD = 1e9 + 7;
long long X = 2147483647;

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

int rabinKarp(string s, string t)
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
    return res.size();
}
string binarySearch(string arr[], int l, int r, string x)
{

    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return arr[mid];
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return "";
}

int main()
{
    // cout << rabinKarp("ababababac", "aba");
    int n;
    vector<pair<string, int>> v;

    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        string a[2000];
        int j = 0;
        while (n--)
        {
            string t;
            cin >> t;
            a[j] = t;
            j++;
        }
        int max = 0;
        string s;
        cin >> s;
        for (int i = 0; i < j; i++)
        {
            int oc = rabinKarp(s, a[i]);
            if (oc >= max)
            {
                max = oc;
            }
            v.push_back(make_pair(a[i], oc));
        }
        cout << max << endl;
        for (auto i : v)
        {
            if (max == i.second)
            {
                cout << i.first << endl;
            }
        }
    }
}