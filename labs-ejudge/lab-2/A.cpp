#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{   int val;
    Node *next;
    Node(int val)
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

    void push(int val)
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
    void print()
    {
        Node *cur = head;
        while (cur != NULL)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
    }

    int near(int k)
    {
        int min = INT32_MAX, index, i = 0;
        Node *cur = head;
        while (cur != NULL)
        {
            if (min > abs(k - cur->val))
            {
                min = abs(k - cur->val);
                index = i;
            }
            i++;
            cur = cur->next;
        }
        return index;
    }
};


    int main()
    {
        int n;
        cin >> n;
        linkedList ll;
        for (int i = 1; i <= n; ++i)
        {
            int x;
            cin >> x;
            ll.push(x);
        }
        int k ; cin >> k;

        cout << ll.near(k);
      

    }