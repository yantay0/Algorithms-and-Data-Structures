#include <iostream>
#include <vector>
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

    Node *preOrder(Node *cur)
    {
        if (cur != NULL)
        {
            preOrder(cur->left);
            preOrder(cur->right);
        }
        return root;
    }
    int _getHeight(Node *node)
    {
        if (!node->left && !node->right)
            return 0;
        int left = 0;
        if (node->left)
            left = _getHeight(node->left);
        int right = 0;
        if (node->right)
            right = _getHeight(node->right);
        return (max(left, right) + 1);
    }
    void _calculateLevelSum(Node *node, int level, int sum[])
    {
        if (node == NULL)
            return;
        sum[level] += node->val;
        _calculateLevelSum(node->left, level + 1, sum);
        _calculateLevelSum(node->right, level + 1, sum);
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
    void search(int x)
    {
        target = search(root, x);
    }
    void preOrderPrint()
    {
        preOrder(root);
    }
    void calculateLevelSum(int level, int sum[])
    {
        _calculateLevelSum(root, level, sum);
    }
    int getHeight()
    {
        return _getHeight(root);
    }
    void print(int arr[], int n)
    {
        cout << n << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << ' ';
        }
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

    int levelOfTree = bst.getHeight() + 1;

    int sum[levelOfTree] = {0};
    bst.calculateLevelSum(0, sum);

    bst.print(sum, levelOfTree);
}