#include <bits/stdc++.h>
using namespace std;


vector<pair<int, pair<int, int>>> ggg;
vector<int> isl(501);

int d_get(int n)
{
    if (n == isl[n])
        return n;
    return isl[n] = d_get(isl[n]);
}
void d_u(int a, int b)
{
    a = d_get(a);
    b = d_get(b);
    if (rand() & 1)
        swap(a, b);
    if (a != b)
        isl[a] = b;
}



int main() {
    int n; cin >> n;
    int point[n];

    for (int i = 0; i < n; i ++) {
        cin >> point[i];
    }


    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ggg.push_back(make_pair(point[i] + point[j], make_pair(i, j)));
        }
    }
    int size = ggg.size();
    int cnt = 0;
    sort(ggg.begin(), ggg.end());
    vector <pair <int, int> > ans;
    isl.resize(n);
    for (int i = 0; i < n; i++)
        isl[i] = i;
    for (int i = 0; i < size; i++) {
        int a = ggg[i].second.first, b = ggg[i].second.second, l = ggg[i].first;
        if (d_get(b)!= d_get(a))
        {
            cnt = cnt + l;
            ans.push_back(ggg[i].second);
            d_u(a, b);
        }
    }
    cout << cnt;
}