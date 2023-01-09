#include <iostream>
#include <vector>
using namespace std;

vector<int> allPref(string s)
{
    vector<int> pref(s.size());
    pref[0] = 0;
    for (int i = 1; i < s.size(); i++)
    {
        int j = pref[i - 1];
        while (j > 0 && s[j] != s[i])
        {
            j = pref[j - 1];
        }
        if (s[j] == s[i])
        {
            pref[i] = j + 1;
        }
        else
        {
            pref[i] = 0;
        }
    }

    return pref;
}

int main()
{
    string text; cin >> text;
    vector <int> ans = allPref(text);
    cout << text.size()-ans[ans.size()-1];
    
}
