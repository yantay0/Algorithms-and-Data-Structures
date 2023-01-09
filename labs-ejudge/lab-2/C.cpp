#include <iostream>
using namespace std;
struct Node
{
  Node *next;
  int val;
  Node(int val)
  {
    this->val = val;
    this->next = NULL;
  }
};
class LinkedList
{
public:
  Node *head;
  LinkedList()
  {
    head = NULL;
  }

  void push(int n)
  {
    for (int i = 0; i < n; i++)
    {
      int val;
      cin >> val;
      Node *newNode = new Node(val);
      if (head == NULL)
      {
        head = newNode;
      }
      else
      {
        Node *cur = head;
        while (cur != NULL)
        {
          if (cur->next == NULL)
          {
            cur->next = newNode;
            break;
          }
          cur = cur->next;
        }
      }
    }
  }
  void print()
  {
    if (head == NULL)
    {
      return;
    }
    else
    {
      Node *cur = head;
      while (cur != NULL)
      {
        cout << cur->val << " ";
        cur = cur->next;
      }
    }
  }
  void del1()
  {
    Node *cur = head->next;
    Node *prev = head;
    int i = 0;
    if (head == NULL)
      return;
    else
    {
      while (cur != NULL)
      {
        if (i % 2 == 0)
          prev->next = cur->next;
        else
          prev = cur;

        i++;
        cur = cur->next;
      }
    }
  }
};

int main()
{
  int n;
  cin >> n;
  LinkedList ll;
  ll.push(n);
  // ll.del();
  ll.del1();
  ll.print();
}