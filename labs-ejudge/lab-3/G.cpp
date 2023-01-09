#include <iostream>
using namespace std;
int bin_search(int a[],int n, int h,int max){
    int l = 1;
    int r = max;
    int hours = 0;
    int ans ;
    while(l < r){
        int mid = (l+r)/2;

        for(int i = 0; i < n; i++){
            if(a[i] <= mid)hours++;
            else{
                hours+= (a[i]+mid-1)/mid;
            }
        }

        if(hours <= h){
            r = mid;
        }
        else{
            l = mid + 1;
        }
        hours = 0;
    }
    return r;
}

int main(){
    int n; cin >> n;
    int a[n];
    int h; cin >> h;
    int max = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(max < a[i])max = a[i];
    }
  
    cout << bin_search(a,n,h,max);
}