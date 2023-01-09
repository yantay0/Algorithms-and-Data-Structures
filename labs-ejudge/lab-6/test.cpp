#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int n=10;
  map<string, string> mp;

  while (n--)
  {
    string s1, s2;
    cin >> s1 >> s2;
    mp[s1] = s2;
    if (!mp.empty())
    {
      for (auto i : mp)
      {

        if (i.second == s1)
        {
          mp[i.first] = s2;
          mp.erase(s1);
          break;
        }
      }
    }
  }
  cout << mp.size() << endl;
  for (auto i : mp)
  {
    cout << i.first << " " << i.second << endl;
  }
}