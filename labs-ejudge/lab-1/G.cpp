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
 int n;
 cin >> n;
 int prime = 2;
 int index = 0;
 int check = 0;

 while (true)
 {
  if (isPrime(prime))
  {
   index++;
   if (isPrime(index))
   {
    check++;
   }
  }
  if (check == n){
   cout << prime;
  break;
 }
 prime++;
}
}
