#include <iostream>
using namespace std;


int main(){
    int n,k; cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0; 
    int max = -1;
    int sum = 0;

    for(int i = n - 1; i >= 0; i--){
        sum += a[i];
        cnt++;
        if ((n - i) % k != 0)
        {
            if (sum > max)
                max = sum;
        }
        if (cnt == k and (n - i) % k == 0)
        {
            if (sum > max)
                max = sum;
            cnt = 0;
            sum = 0;
        }
    }
    cout << max;
}