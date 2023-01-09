#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<size_t, size_t> hashes;
size_t repeats = 0;
long long mod = 1e9 + 7;

void findPattern(string t, string s)
{

    size_t n = t.size();
    size_t m = s.size();
    long long h[n];
    long long p[n];
    p[0] = 1;
    for (size_t i = 1; i < max(n, m); ++i)
    {
        p[i] = (p[i - 1] * 31) % mod;
    }
    for (size_t i = 0; i < n; ++i)
    {
        h[i] = ((t[i] - int('a') + 1) * p[i]) % mod;
        if (i > 0)
        {
            h[i] = (h[i] + h[i - 1]) % mod;
        }
    }

    long long h_s = 0;
    for (size_t i = 0; i < m; ++i)
    {
        h_s = (h_s + ((s[i] - int('a') + 1) * p[i]) % mod) % mod;
    }
    for (size_t i = 0; i + m - 1 < n; i++)
    {
        long long d = h[i + m - 1];
        if (i > 0)
        {
            d = (d - h[i - 1] + mod) % mod;
        }
        if (d == (h_s * p[i]) % mod)
        {
            hashes[i]++;
            if (hashes[i] > 1)
                repeats++;
        }
    }
}
int main()
{
    string s1, s2, pattern;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, pattern);

    findPattern(s1, pattern);
    findPattern(s2, pattern);

    cout << repeats;

}