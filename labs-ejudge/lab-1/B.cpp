#include <iostream>
#include <stack>
using namespace std;
int main()
{
  int n ; cin >> n;
  int a[n];
  stack <int> s;
  int x , i = 0;

 for(int i = 0 ; i < n ; i++)cin >> a[i];


  while(n--){
    while(!s.empty() and  s.top() > a[i]){
      s.pop();
    }
    if(s.empty()) cout << -1 << " ";
    else cout << s.top() << " " ;
    s.push(a[i]);
    i++;
  }
  }
  

 

  

