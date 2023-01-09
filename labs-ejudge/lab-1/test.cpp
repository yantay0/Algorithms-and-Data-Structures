#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> twoSum(vector <long long> v, int target)
{
   vector <long long> ans;
   int start = 0;
   int end = v.size() - 1;
   while (start < end)
   {
      int sum = v[start] + v[end];
      if (sum == target)
      {
         ans.push_back(v[start + 1]);
         ans.push_back(v[end-1]);
          return ans;
      }
      if (sum > target)
      {
         end--;
      }
      else
      {
         start++;
      }
   }

   return ans;
}


int main()
{
   int n;
   long long m;
   cin >> m >> n;
   vector <long long> v;

   for (int i = 0; i < n; i++){
      int x; cin >> x;
      v.push_back(x);
   }

for(int i = 0; i < 2; i++)cout << twoSum(v,m)[i] << " ";
}