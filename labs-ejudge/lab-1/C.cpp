#include <iostream>
#include <stack>
using namespace std;
string solve (string s){
 stack<char> st1;
 string ans = "";
 for (int i = 0; i < s.size(); i++)
 {
  if (s[i] != '#')
   st1.push(s[i]);
}

for (int i = 0; i <=  s.size(); i++)
{
 if (s[i] == '#')st1.pop();
}

while (!st1.empty())
{
 ans += st1.top();
 st1.pop();
}
return ans;
}

int main()
{


 string s,t;
 cin >> s  >> t;
 int cnt = 0;

 solve(s) == solve(t) ?  cout << "Yes" : cout <<  "No";



}
