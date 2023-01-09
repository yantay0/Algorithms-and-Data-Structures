#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int x)
    {
        this->val = x;
        this->left = this->right = NULL;
    }
};

struct Bst
{
    Node *root;

    Bst()
    {
        this->root = NULL;
    }

    Node *add(Node *cur, int x)
    {
        if (cur == NULL)
        {
            cur = new Node(x);
        }
        else if (cur->val > x)
        {
            if (cur->left == NULL)
                cur->left = add(cur->left, x);
            else
                add(cur->left, x);
        }
        else
        {
            if (cur->right == NULL)
                cur->right = add(cur->right, x);
            else
                add(cur->right, x);
        }
        return cur;
    }
};

int main()
{
    Bst *B = new Bst();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (B->root == NULL)
            B->root = B->add(B->root, x);
        else
            B->add(B->root, x);
    }

    while (m--)
    {
        string s;
        cin >> s;
        Node *cur = B->root;
        for (int i = 0; i < s.length(); i++)
        {
            if (cur == NULL)
            {
                break;
            }
            if (s[i] == 'L')
            {
                cur = cur->left;
            }
            if (s[i] == 'R')
            {
                cur = cur->right;
            }
        }
        if (cur != NULL)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}