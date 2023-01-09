#include <iostream>
//#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct node
{
    int val;
    node *nxt, *prev;
    node() { val = 0, nxt = NULL; }
    node(int x) { val = x, nxt = NULL; }
};

struct list
{
    node *head = NULL;

    node *get(int p)
    {
        if (p < 0)
        {
            cout << "[Error] Index out of bounds (get)\n";
            exit(0);
        }
        node *cur = head;
        for (int i = 0; i < p && cur != NULL; i++)
            cur = cur->nxt;
        return cur;
    }

    node *get_tail()
    {
        if (head == NULL)
        {
            cout << "[Error] the list has no tail\n";
            exit(0);
            return NULL;
        }
        node *tail = head;
        while (tail->nxt != NULL)
            tail = tail->nxt;
        return tail;
    }

    void append(int x)
    { // add to the end
        if (head == NULL)
        {
            head = new node(x);
            return;
        }
        node *tail = get_tail();
        tail->nxt = new node(x);
    }

    void insert(int p, int x)
    { // list.get(p).val == x at the end
        if (p < 0)
        {
            cout << "[Error] negative index (insert)\n";
            exit(0);
        }
        if (p == 0)
        {
            node *newNode = new node(x);
            newNode->nxt = head;
            head = newNode;
            return;
        }
        node *prev = get(p - 1);
        if (prev == NULL)
        {
            cout << "[Error] index out of bounds (insert)\n";
            exit(0);
        }
        node *newNode = new node(x);
        newNode->nxt = prev->nxt;
        prev->nxt = newNode;
    }

    void out()
    {
        node *cur = head;
        while (cur != NULL)
        {
            cout << cur->val << " ";
            cur = cur->nxt;
        }
        cout << "\n";
    }
};

int main()
{

    list *L = new list();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        L->append(a);
    }
    int num, p;
    cin >> num >> p;
    L->insert(p, num);

    L->out();

    return 0;
}