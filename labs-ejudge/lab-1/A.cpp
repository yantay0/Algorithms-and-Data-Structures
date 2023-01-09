#include <iostream>
#include <deque>
using namespace std;
int main()
{
 int n;
 cin >> n;

 deque<int> d;

 while (n--)
 {
  int x;
  cin >> x;

  for (int i = x; i > 0; i--)
  {
   d.push_back(i);

   for (int j = 0; j <= i; j++)
   {
    int num = d.back();
    d.pop_back();
    d.push_front(num);
   }
  }
  while (!d.empty())
  {
   cout << d.front() << " ";
   d.pop_front();
  }
  cout << endl;
 }
}