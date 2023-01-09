#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *right;
    Node *left;
    Node(int val)
    {
        this->val = val;
        right = left = NULL;
    }
};

class BST
{
private:
    Node *root;

    Node *push(Node *cur, int val)
    {
        if (cur == NULL)
        {
            return new Node(val);
        }
        else if (val < cur->val)
        {
            cur->left = push(cur->left, val);
        }
        else
        {
            cur->right = push(cur->right, val);
        }
        return cur;
    }

    Node *target;

    Node *search(Node *cur, int x)
    {
        if (cur != NULL)
        {
            search(cur->left, x);
            search(cur->right, x);
            if (cur->val == x)
            {
                target = cur;
            }
        }
        return target;
    }

    Node *preOrder(Node *cur)
    {
        if (cur != NULL)
        {
            cout << cur->val << " ";
            preOrder(cur->left);
            preOrder(cur->right);
        }
    }

public:
    BST()
    {
        root = NULL;
    }
    void push(int val)
    {
        root = push(root, val);
    }
    void searh(int x)
    {
        target = search(root, x);
    }
    void preOrderPrint()
    {
        preOrder(target);
    }
};
int main()
{
    BST bst;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        bst.push(x);
    }
    int t;
    cin >> t;
    bst.searh(t);
    bst.preOrderPrint();
}