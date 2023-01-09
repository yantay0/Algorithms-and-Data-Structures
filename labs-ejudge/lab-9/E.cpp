#include <iostream>
#include <vector>
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
int lps(const std::string &str)
{

    int n = str.length();

    if (n < 2)
    {
        return 0;
    }

    int len = 0;
    int i = n / 2;

    while (i < n)
    {
        if (str[i] == str[len])
        {
            ++len;
            ++i;
        }
        else
        {
            if (len == 0)
            { // no prefix
                ++i;
            }
            else
            { // search for shorter prefixes
                --len;
            }
        }
    }

    return len;
}
int main()
{
    int n; cin >> n;
    string ans = "";
    int ok;
    // string s = "nugman";
    // vector <int> v = prefixFunction(s);
    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i] << endl;
    // }
    while(n--){
        string s;
        cin >> s;
        int k; cin >> k;
        // string ans = "";
        int x = prefixFunction(s)[prefixFunction(s).size()-1];
        int ans = s.size()-x;
        cout << ans*(k-1)+s.size()<< endl;
    }
}


