#include <iostream>
#include <stack>
using namespace std;

int main()
{
  int n; cin >> n;
  int a[n];
  int cnt = 0 , max = 0 , mode ;

  for(int i = 0; i < n; i++)cin >> a[i];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(a[i]==a[j])cnt++;
    }
    if(cnt > max){
      max = cnt;
      mode = a[i];
    }
    cnt = 0;
  }
  cout << mode;
}
