#include <iostream>
#include <vector>
using namespace std;
// int n = 5000000;
// int *a = new int[n];
vector<int> a(500000);

string findLcs(string s, string t)
{

    int num;
    int lcs = 0;
    for (int i = 0; i < t.size(); i++)
    {
        for (int j = s.size() - 1; j >= 0; j--)
        {
            if (s[j] == t[i])
                a[j + 1] = a[j] + 1;
            else
                a[j + 1] = 0;

            if (a[j + 1] > lcs)
            {
                lcs = a[j + 1];
                num = j - lcs + 1;
            }
        }
    }
    if (lcs != 0)
        return s.substr(num, lcs);
}

int main()
{
    int k;
    cin >> k;
    string firstText;
    cin >> firstText;

    while (k - 1 != 0)
    {
        string text;
        cin >> text;
        firstText = findLcs(firstText, text);
        k--;
    }
    cout << firstText;
}