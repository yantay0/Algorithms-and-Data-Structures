#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *right, *left;
    Node(int val)
    {
        this->val = val;
        right = left = NULL;
    }
};
struct bst
{
    Node *root;
    bst()
    {
        this->root = NULL;
    }

    Node *add(Node *cur, int val)
    {
        if (cur == NULL)
        {
            cur = new Node(val);
        }
        else if (val > cur->val)
        {

            cur->right = add(cur->right, val);
        }
        else
        {
            cur->left = add(cur->left, val);
        }

        return cur;
    }

    void preOrder(Node *cur)
    {
        if (cur != NULL)
        {
            preOrder(cur->left);
            cout << cur->val << " ";
            preOrder(cur->right);
        }
    }
};

int main()
{
    bst *B = new bst();
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (B->root == NULL)
            B->root = B->add(B->root, x);
        else
            B->add(B->root, x);
    }

    B->preOrder(B->root);
