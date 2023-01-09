#include <iostream>
using namespace std;
int size;
struct Node{
    string val;
    Node * next;

    Node(string val){
        this->val = val;
        next = NULL;
    }
};

class LinkedList{
public:
    Node *head, *tail;
    LinkedList(){
        head = NULL;
    }

    void push_front(string val){
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }


    void print(){
        Node *cur = head;
        while(cur!=NULL){
            cout << cur -> val << endl;
            cur = cur -> next;
        }
    }


};
int main(){
    int n; cin >> n;
    LinkedList ll;
    for(int i = 0; i < n; i++){
        string x; cin >> x;
        if (i == 0)ll.push_front(x);
        else{
            if (x != ll.head->val)
                ll.push_front(x);}
    }

   cout << "All in all: " << size << endl << "Students:\n" ;

        ll.print();
}