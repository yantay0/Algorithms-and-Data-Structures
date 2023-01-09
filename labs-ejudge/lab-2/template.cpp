#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    char val;
    bool was;
    Node *next;
    Node(char val)
    {
        this->val = val;
        next = NULL;
    }
};

class LinkedList
{
public:
    int size;
    Node *head;
    Node *tail;
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void pushBack(char val)
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
                    cur->was = true;
                    return;
                }
                cur = cur->next;
            }
            tail->next = node;
            tail = node;
        }
        size++;
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

    bool contains(int val)
    {
        Node *cur = head;
        while (cur != NULL)
        {
            if (cur->val == val)
            {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    void answer()
    {
        Node *cur = head;
        while (cur != NULL)
        {
            if (cur->was == false)
            {
                cout << cur->val << " ";
                break;
            }
            if (cur->next == NULL)
            {
                cout << "-1"
                     << " ";
            }
            cur = cur->next;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        LinkedList *ll = new LinkedList();
        cin >> x;
        char c;
        for (int j = 0; j < x; j++)
        {
            cin >> c;

            ll->pushBack(c);
            ll->answer();
        }
        cout << endl;
    }