#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m, k;
    int di[n];
    int a[n][n];

    for(int i = 0; i < n; i++) {
        di[i] = -1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cin >> m >> k;
    m = m - 1;
    k = k - 1;
    di[m] = 0;
    queue <int> q;
    q.push(m);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int j = 0; j < n; j++) {
            if(a[cur][j] == 1 and di[j] == -1) {
                di[j] = di[cur] + 1;
                q.push(j);
            }
        }
    }
    cout << di[k];
    return 0;
}