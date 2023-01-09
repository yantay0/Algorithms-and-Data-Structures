#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std;

int main() {






    int n;
    cin >> n;

    vector<vector<pair<int, long long>>> hhh(n + 1);
    vector<long long> d(n + 1, 1e15), v(n + 1, -1);
    bool check = false;
    int cnt = 0;


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long long  c;
            cin >> c;
            if (c == 100000) continue;
            hhh[i + 1].push_back({ j + 1,c });
            cnt++;
        }
    }


    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (auto a : hhh[j]) {
                long long point = a.first, c = a.second;
                if (c + d[j] < d[point] )
                {
                    d[point] = c + d[j];
                    v[point] = j;
                }
            }
        }
    }




   
    for (int i = 1; i <= n; ++i) {
        for (auto k : hhh[i]) {
            long long point = k.first, c = k.second;
            if (c + d[i] < d[point] )
            {
                d[point] = c + d[i];
                v[point] = i;
                check = true;
            }

            if (check) {
                cout << "YES" << "\n";

                vector<int >hh;
                vector<bool>visited(n + 1, false);

                while (!visited[i]) {
                    visited[i] = true;
                    i = v[i];
                }

                int u = i;
                hh.push_back(u);
                u = v[u];
                while (u ^ i) {
                    hh.push_back(u);
                    u = v[u];
                }
                hh.push_back(u);
                reverse(hh.begin(), hh.end());

                cout << hh.size() << "\n";
                for (auto cur : hh)
                 cout << cur << " ";
                return 0;
            }
        }
    }

    if (!check)
        cout << "NO" << "\n";
}