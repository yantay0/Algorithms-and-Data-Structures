#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(Node *next) : val(0), next(next) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

Node *insert(Node *head, Node *node, int p)
{
    if(p==0){
        node->next = head;
        head = node;
        return head;
    }
    else{
        Node * cur = head;
        while(--p>0){
            cur = cur -> next;
        }
        node->next = cur->next;
        cur->next = node;
        return head;
    }
}

Node *remove(Node *head, int p)
{
    /* write your code here */
    if(p==0){
          Node *newHead = head->next;
        head->next = head;
        delete head;
        return newHead;
    }
    else{
        Node *cur = head;
        while(--p > 0){
            cur = cur-> next;
        }
        Node* del = cur->next; // 3
        cur->next = cur->next->next; // 
        delete del;// 1 3 4 5
        return head;
    }
}

Node *replace(Node *head, int p1, int p2)
{
    /* write your code here */
    Node *node = head;
    if(p1!=0){
        Node *cur = head;
        while(--p1){
            cur = cur -> next;
        }
        node = cur->next;
        cur->next = cur ->next -> next;
    }
    else{
        node = head;
        head = head -> next;
    }
    return insert(head,node,p2);
    
}

Node *reverse(Node *head)
{
    /* write your code here */
    Node * prev = NULL;
    Node * cur = head;
    Node * next = NULL;
    while(cur != NULL){
        next = cur->next; 
        cur->next = prev; 
        prev = cur; 
        cur = next; 
    }
    return prev;
}

void print(Node *head)
{
    /* write your code here */
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

Node *cyclic_left(Node *head, int x)
{
    /* write your code here */
    if(!x)return head;
    Node *newHead = head;
    Node *prev = NULL;
    while(x--){// 1 2 3 4
        prev = newHead; // 2
        newHead = newHead -> next;// 3
    }
    Node *tail = newHead;
    while (tail->next)
        tail = tail->next;
    tail->next = head;
    prev->next = NULL;
    return newHead;
}

Node *cyclic_right(Node *head, int x)
{
    /* write your code here */
    if (!x)
        return head;
    Node *tail = head;
    int sz = 0;
    while (tail->next)
    {
        sz++;
        tail = tail->next;
    }
    int ind = sz - x;
    Node *last = head;
    for (int i = 0; i < ind; i++)
    {
        last = last->next;
    }

    Node *new_head = last->next;
    last->next = NULL;
    tail->next = head;
    return new_head;
}

int main()
{
    Node *head = nullptr;
    while (true)
    {
        int command;
        cin >> command;
        if (command == 0)
        {
            break;
        }
        else if (command == 1)
        {
            int x, p;
            cin >> x >> p;
            head = insert(head, new Node(x), p);
        }
        else if (command == 2)
        {
            int p;
            cin >> p;
            head = remove(head, p);
        }
        else if (command == 3)
        {
            print(head);
        }
        else if (command == 4)
        {
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }
        else if (command == 5)
        {
            head = reverse(head);
        }
        else if (command == 6)
        {
            int x;
            cin >> x;
            head = cyclic_left(head, x);
        }
        else if (command == 7)
        {
            int x;
            cin >> x;
            head = cyclic_right(head, x);
        }
    }
    return 0;
}