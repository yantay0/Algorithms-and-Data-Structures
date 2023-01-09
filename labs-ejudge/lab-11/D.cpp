#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<bool> was;
vector<int> ggg, small;
vector <vector <int>> rr;

int main()
{

   
    int n;
    cin >> n;
    int res = 0;
    int cost = 1e15;
    was.resize(n);
    small.assign(n, cost);
    // small.assign(n, cost);
    ggg.assign(n, -1);
    rr.resize(n);
    small[0] = 0;
    for (int i = 0; i < n; i++) rr[i].resize(n);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cin >> rr[i][j];
        
    }


    for (int i = 0; i < n; i++)
    {
        int c = -1;
        for (int j = 0; j < n; j++)
        {
            if ((c == -1 || small[j] < small[c])  and !was[j])
                c = j;
        }

        was[c] = true;

        if (ggg[c] != -1)
        {
            res += rr[c][ggg[c]];
        }
        for (int j = 0; j < n; j++)
        {
            if (small[j]> rr[c][j])
            {
                small[j] = rr[c][j];
                ggg[j] = c;
            }
        }
    }
    cout << res << endl;
}