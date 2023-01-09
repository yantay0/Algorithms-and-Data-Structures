#include <iostream>
using namespace std;
int size = 0;
struct Node{
    int val;
    Node *right,*left;
    Node(int val){
        this->val = val;
        right = left = NULL;
    }
};

struct bst{
    Node *root;
    bst(){
        root = NULL;
    }
    Node * push(Node *cur,int val){
        if(cur == NULL){
            cur = new Node(val);
        }
        else if(cur->val < val){
            cur->right = push(cur->right,val);
        }
        else{
            cur->left = push(cur->left,val);
        }
        return cur;
    }

    Node * inOrder(Node * cur){
        if(cur != NULL){
            inOrder(cur->left);
          //  cout << cur->val << " ";
            inOrder(cur->right);
            size++;
        }
        
    }

    void  preOrder(Node *cur){
        if(cur != NULL){
            cout << cur->val << " ";
            preOrder(cur->left);
            preOrder(cur->right);
         }
    }
    void postOrder(Node *cur)
    {
        
        if (cur != NULL)
        {
            postOrder(cur->left);
            postOrder(cur->right);
            cout << cur->val << " ";
        }
    }
    Node *target;

    Node * search(Node *cur,int x){
        if(cur != NULL){
            search(cur->left,x);
            search(cur->right,x);
            if(cur->val==x){
                target = cur;
            }
        }
        return target;
    }
};
int main(){
    bst *B = new bst();
    int n,m; cin >> n;

    while(n--){
        int x; cin >> x;
        if(B->root == NULL){
            B->root = B->push(B->root,x);
        }
        else {
            B->push(B->root,x);
        }
    }
    
    cin >> m;
    

    B->preOrder(B->search(B->root,m));

}
    