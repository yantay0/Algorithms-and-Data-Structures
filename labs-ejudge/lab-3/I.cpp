#include <iostream>
#include <deque>
#include <string>
#include <queue>
#include <map>

using namespace std;

int main()
{
 int n;
 cin >> n;
 queue<char> q;
 string s;
 cin >> s;
 map<char, int> del;
 map<char, int> cnt;
 for (int i = 0; i < s.size(); i++)
 {
  q.push(s[i]);
  cnt[s[i]]++;
 }
 while (cnt['S'] > 0 and cnt['K'] > 0)
 {
  if (del[q.front()] > 0)
  {
   cnt[q.front()]--;
   del[q.front()]--;
   q.pop();
  }
  else
  {
   if (q.front() == 'S')
    del['K']++;
   else
    del['S']++;
   q.push(q.front());
   q.pop();
  }
 }
 cout << ((cnt['S'] > 0) ? "SAKAYANAGI" : "KATSURAGI");
}