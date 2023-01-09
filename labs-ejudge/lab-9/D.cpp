#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> prefixFunction(string s)
{
    s[0] = s[0] + 32;
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
    string prev;
    cin >> prev;
    int n;
    cin >> n;
    int max = 0;
    string a[n];
    string ans[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        vector<int> v = prefixFunction(a[i] + prev);
        if (max < v[v.size() - 1])
        {
            max = v[v.size() - 1];
        }
        // cout << max << " ";
    }

    if(max == 0){
        cout << 0;
    }
    else{

    
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> v = prefixFunction(a[i] + prev);
        if (max == v[v.size() - 1])
        {
            // cout << a[i] << endl;
            ans[j] = a[i];
            j++;
        }
    }
    cout << j << endl;
    for (int i = 0; i <= j; i++)
    {
        cout << ans[i] << endl;
    }
    }

    // while(n--){
    //     string s; cin >> s;
    //     s[0] = s[0] + 32;
    //     vector <int> v = prefixFunction(s+prev);
    //     if(max <= v[v.size()-1]){
    //         max = v[v.size()-1];
    //         ans.push_back(s);
    //     }
    // }
}