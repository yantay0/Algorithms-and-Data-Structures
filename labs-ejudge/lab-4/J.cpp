#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int size = 0;
vector<int> v1, v2;
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
    //Node *root;

    Node *push(Node *cur, int val)
    {
        if (cur == NULL)
        {
            return new Node(val);
        }
        else if (val < cur->val)
        {
            cur->left = push(cur->left, val);
            v1.push_back(val);
        }
        else
        {
            cur->right = push(cur->right, val);
            v2.push_back(val);
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

       void preOrder(Node *node)
    {
        if (!node)
            return;
        cout << node->val << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

public:
    Node *root;
    BST()
    {
        root = NULL;
    }
    void push(int val)
    {
        root = push(root, val);
    }
    void search(int x)
    {
        target = search(root, x);
    }
    void preOrderPrint()
    {
        preOrder(root);
    }
    Node *balance(vector<int> &v, int l, int r)
    {
        if (l > r)
            return NULL;
        int m = l + (r - l) / 2;
        Node *root = new Node(v[m]);
        root->left = balance(v, l, m - 1);
        root->right = balance(v, m + 1, r);
        return root;
    }
    Node * getRoot(){
        return root;
    }
};
int main()
{
    BST bst;

    int n;
    cin >> n;
    int size = pow(2, n) - 1;
    vector<int> v(size);
    for (int i = 0; i < size; i++) cin >> v[i];
    

    sort(v.begin(), v.end());


    bst.root = bst.balance(v, 0, size - 1);
    bst.preOrderPrint();
}