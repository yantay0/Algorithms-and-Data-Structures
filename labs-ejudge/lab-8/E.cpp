#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<char> getPrefix(long long arr[], int n)
{
    vector<char> hashes(n);
    for (int i = 0; i < n; i++)
    {
        long long cur = arr[i];
        if (i != 0)
            cur -= arr[i - 1];
        hashes[i] = (long long)(cur / pow(2, i)) + 'a';
    }
    return hashes;
}

int main()
{
    int n;
    cin >> n;
    long long b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (auto i : getPrefix(b, n))
        cout << i;
}