#include <iostream>
using namespace std;

void countPattern(string text, string pattern)
{
    int cnt = 0;
    int n = text.length();
    int m = pattern.length();

    int j;
    for (int i = 0; i <= n - m; i++)
    {

        for (j = 0; j < m; ++j)
        {
            if (pattern[j] != text[i + j])
            {
                break;
            }
        }

        if (j == m)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main()
{
    string text;
    cin >> text;
    long long n;
    cin >> n;
    while (n--)
    {
        long long x, y;
        cin >> x >> y;
        string sub = "";
        for (long long i = x - 1; i < y; i++)
        {
            sub += text[i];
        }
        countPattern(text, sub);
    }
}