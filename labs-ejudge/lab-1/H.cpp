#include <iostream>
#include <stack>
using namespace std;
bool isPrime(int x)
{
 for (int i = 2; i < x; i++)
 {
  if (x % i == 0)
   return false;
 }
 if (x == 1)
  return false;
 return true;
}
int main()
{
 int n ; cin >> n;
 if(isPrime(n))cout << "YES";
 else cout << "NO";
}