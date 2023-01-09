#include <iostream>
using namespace std;

struct Node
{
    char val;
    bool repeat;
    Node *next;
    Node(char val)
    {
        this->val = val;
        next = NULL;
    }
};

class linkedList
{
public:

    Node *head;
    Node *tail;
   linkedList()
    {
        head = tail = NULL;
    }

    void push(char val)
    {
        Node *node = new Node(val);
        if (head == NULL)
        {
            head = tail = node;
        }
        else
        {
            Node *cur = head;
            while (cur != NULL)
            {
                if (cur->val == val)
                {
                    cur->repeat = true;
                    return;
                }
                cur = cur->next;
            }
            tail->next = node;
            tail = node;
        }
      
    }
    void solve()
    {
        Node *cur = head;
        while (cur != NULL)
        {
            if (cur->repeat == false)
            {
                cout << cur->val << " ";
                break;
            }
            if (cur->next == NULL)
            {
                cout << -1 << " ";
            }
            cur = cur->next;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
       linkedList *ll = new linkedList();
       int x;
       cin >> x;
       char c;
       for (int j = 0; j < x; j++)
       {
           cin >> c;

           ll->push(c);
           ll->solve();
        }
        cout << endl;
    }
}