#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node
{
  int val;
  Node *next;

  Node()
  {
    val = 0;
    next = NULL;
  }
};

void mode(Node *head)
{
  vector<int> v;
  Node *cur = head;
  Node *cur1 = head;
  int cnt = 0, max = 0, max2 = 0;

  while (cur != NULL)
  {
    while (cur1 != NULL)
    {
      if (cur->val == cur1->val)
      {
        cnt++;
      }
      cur1 = cur1->next;
    }
    if (cnt > max)
    {
      max = cnt;
    }
    cnt = 0;
    cur1 = head;
    cur = cur->next;
  }

  cur = head;
  cur1 = head;

  while (cur != NULL)
  {
    while (cur1 != NULL)
    {
      if (cur->val == cur1->val)
      {
        cnt++;
      }
      cur1 = cur1->next;
    }
    if (cnt > max2)
    {
      max2 = cnt;
    }
    cnt = 0;
    cur1 = head;

    if (max == max2)
    {
      v.push_back(cur->val);
    }
    max2 = 0;
    cur = cur->next;
  }
  sort(v.begin(), v.end());
  for (int i = v.size() - 1; i >= 0; i--)
  {
    if (v[i] != v[i - 1])
      cout << v[i] << " ";
  }
}

int main()
{
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i)
  {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur->val = x;

    if (i == 1)
    {
      head = tail = cur;
    }
    else
    {
      tail->next = cur;
      tail = cur;
    }
  }

  mode(head);
  return 0;
}