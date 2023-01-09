#include <iostream>
using namespace std;
struct Node
{
    char val;
    bool repeat;
    Node *next;
    Node(char val)
    {
        this->val = val;
        next = NULL;
    }
};

class linkedList
{
public:
    Node *head, *tail;
    linkedList()
    {
        head = tail = NULL;
    }

    void push(char val)
    {
        Node *cur = new Node(val);
        if (head == NULL)
        {
            head = tail = cur;
        }
        else
        {
            Node *cur = head;
            while (cur != NULL)
            {
                if (cur->val == val)
                {
                    cur->repeat = true;
                    return;
                }
                cur = cur->next;
            }
            tail->next = cur;
            tail = cur;
        }
    }

    bool isRepeated(char val){
        Node *cur = head;
        while(cur!=NULL){
            if(cur->val==val)return true;
            cur = cur->next;
        }
        return false;
    }
    
    void check(){
        Node *cur = head;
        while(cur!=NULL){
            if(cur->repeat == false){
                cout << cur->val << " ";
                break;
            }           
            if(cur->next == NULL){
                cout << -1 << " ";
            }
            cur = cur->next;
        }

    }
  
};

int main()
{
  
   int n; cin >> n;
  
      while(n--){

       int x; cin >> x;
      linkedList ll;
       for(int i = 0; i < x; i++){
           char c; cin >> c;
           ll.push(c);
           ll.check();
       }
       cout << endl;

      }

}
