#include <iostream>
#include <map>
#include <queue>
using namespace std;
int main()
{
  int n; cin >> n;
  string s; cin >> s;
  queue <char> q;
  map <char,int> cnt,del;

  for(int i = 0; i < s.size(); i++)
  {
    q.push(s[i]);
    cnt[s[i]]++;
  }

  while(cnt['S'] > 0 and cnt['K'] > 0){
    if(del[q.front()] > 0){
      cnt[q.front()]--;
      del[q.front()]--;
    }
    else if(cnt[q.front()]=='S'){
      del[q.front()]++;
      q.push(q.front());
      q.pop();
    }
  }

  if(cnt['S'] > 0)cout << "S";
  else cout << 'K';

}
