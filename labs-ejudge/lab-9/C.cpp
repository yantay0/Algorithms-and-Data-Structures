#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> prefixFunction(string s)
{
    vector<int> pi(s.size());
    pi[0] = 0;
    for (int i = 1; i < s.size(); i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i])
        {
            j = pi[j - 1];
        }
        if (s[j] == s[i])
        {
            pi[i] = j + 1;
        }
        else
        {
            pi[i] = 0;
        }
    }

    return pi;
}

vector<int> kmp(string s, string t)
{
    s = t + '#' + s;
    vector<int> res;
    vector<int> pi = prefixFunction(s);
    for (int i = 0; i < s.size(); i++)
    {
        if (pi[i] == t.size())
        {
            res.push_back(i - 2 * t.size());
        }
    }
    return res;
}

int main()
{
    string s, t;
    cin >> s >> t;
    string ans = "";
    // cout << s+s;
    vector <int> v = prefixFunction(t+s);
    int d = s.size()-v[v.size()-1];
    reverse(s.begin(), s.begin() + d);
    reverse(s.begin() + d, s.end());
    reverse(s.begin(), s.end());
    if(s==t){
        cout << v[v.size() - 1];
    }
    else cout << -1;
    // for(int i = 0; i < s.size()-v[v.size()-1]; i++){
    //     ans+=s[i];
    // }
    // for (int i = s.size() - v[v.size() - 1]-1; i++)
    // {
    //     ans += s[i];
    // }
}
