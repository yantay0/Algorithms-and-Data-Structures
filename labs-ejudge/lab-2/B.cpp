#include <iostream>
#include <vector>
using namespace std;
struct Node
{
  string val;
  Node *next;
  Node(string val)
  {
    this->val = val;
    next = NULL;
  }
};

class linkedList
{
public:
  Node *head, *tail;
  linkedList()
  {
    head = tail = NULL;
  }

  void push(string val)
  {
    Node *cur = new Node(val);
    if (head == NULL)
    {
      head = tail = cur;
    }
    else
    {
      tail->next = cur;
      tail = cur;
    }
  }
  void push_back(string val)
  {
    Node *cur = head;
    while (cur != NULL)
    {
      if (cur = tail)
      {
        Node *node = new Node(val);
        tail->next = node;
        tail = node;
        break;
      }
      cur = cur->next;
    }
  }
void rotateLeft(int k){
  vector <string> v;

  while(k--){
    Node *temp = head;
    head = head->next;
    v.push_back(temp->val);
    delete temp;
  }

  for(auto i : v){
    push_back(i);
  }
}

void print(){
  Node *cur = head;
  while(cur!=NULL){
    cout << cur->val << " ";
    cur = cur->next;
  }
}

};
int main()
{
  int n;
  cin >> n;
  int k;
  cin >> k;
  linkedList ll;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    ll.push(s);
  }

 
  ll.rotateLeft(k);
  ll.print();
}