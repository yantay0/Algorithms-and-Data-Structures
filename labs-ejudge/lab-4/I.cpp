#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int val, cnt;
    Node *right;
    Node *left;
    Node(int val)
    {
        cnt = 1;
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
        if (!cur)
        {
            return new Node(val);
        }
        if (cur->val == val)
        {
            cur->cnt++;
        }
        if (val > cur->val)
        {
            cur->right = push(cur->right, val);
        }
        else if (val < cur->val)
        {
            cur->left = push(cur->left, val);
        }
        return cur;
    }

    Node *target;

    Node *_search(Node *cur, int target)
    {
        if (!cur)
            return NULL;
        if (cur->val == target)
            return cur;
        if (cur->val > target)
            return _search(cur->left, target);
        return _search(cur->right, target);
    }
    int mostRight(Node *cur)
    {
        if (!cur)
            return -1;
        if (!cur->right)
            return cur->val;
        return mostRight(cur->right);
    }

    int mostLeft(Node *cur)
    {
        if (!cur)
            return -1;
        if (!cur->left)
            return cur->val;
        return mostLeft(cur->left);
    }
    Node *remove(Node *cur, int target)
    {
        if (!cur)
            return NULL;
        if (cur->val == target)
        {
            if (!cur->right && !cur->left)
            {
                return NULL;
            }
            else if (cur->left && !cur->right)
            {
                Node *temp = cur->left;
                return temp;
            }
            else if (cur->right && !cur->left)
            {
                Node *temp = cur->right;
                return temp;
            }
            else if (cur->right && cur->left)
            {
                cur->val = mostRight(cur->left);
                cur->left = remove(cur->left, cur->val);
            }
        }
    }
    void printInOrder(Node *node)
    {
        if (node == NULL)
            return;
        printInOrder(node->left);
        cout << node->val << " ";
        printInOrder(node->right);
    }

public:
    BST()
    {
        root = NULL;
    }
    Node *search(int x)
    {
       return _search(root, x);
    }
    Node *Findroot()
    {
        return root;
    }
    void push(int val)
    {

        Node *newNode = push(root, val);
        if (root == NULL)
            root = newNode;
    }
    void remove(int target)
    {
        root = remove(root, target);
    }
    void printInOrder()
    {
        printInOrder(root);
    }
};
int main()
{
    BST bst;

    int n, x, sum = 0;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s >> x;
        if (s == "insert")
        {
            Node *prev = bst.search(x);
            if (prev)
            {
                prev->cnt++;
            }
            else
            {
                bst.push(x);
            }
        }
        if (s == "delete")
        {
            Node *prev = bst.search(x);
            if (prev->cnt == 0)
            {
                bst.remove(x);
            }
            else
            {
                prev->cnt--;
            }
        }
        if (s == "cnt")
        {
            Node *prev = bst.search(x);
            if (prev)
            {
                cout << prev->cnt;
            }
            else
            {
                cout << 0;
            }
            cout << endl;
        }
    }
}