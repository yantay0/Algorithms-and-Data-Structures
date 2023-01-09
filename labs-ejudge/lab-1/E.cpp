#include <iostream>
#include <queue>
using namespace std;
int main()
{

  queue<int> b, n;
  int x;

  for (int i = 0; i < 5; i++)
  {
    cin >> x;
    b.push(x);
  }

  for (int i = 0; i < 5; i++)
  {
    cin >> x;
    n.push(x);
  }

  int cnt = 0;

  while (!b.empty() and !n.empty())
  {

    if (b.front() == 0 and n.front() == 9)
    {
      b.push(b.front());
      b.push(n.front());
    }

    else if (b.front() == 9 and n.front() == 0)
    {
      n.push(b.front());
      n.push(n.front());
    }
    else
    {
      if (b.front() > n.front())
      {
        b.push(b.front());
        b.push(n.front());
      }
      else
      {
        n.push(b.front());
        n.push(n.front());
      }
    }

    b.pop();
    n.pop();

    cnt++;
    if (cnt >= 1000000)
    {
      cout << "blin nichya";
      break;
    }
  }

  if (b.empty())
    cout << "Nursik " << cnt;
  else if (n.empty())
    cout << "Boris " << cnt;
}