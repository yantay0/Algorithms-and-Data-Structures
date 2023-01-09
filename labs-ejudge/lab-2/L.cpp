#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        next = NULL;
    }
};

class linkeList{
public:
    Node *head,*tail;
    linkeList(){
        head = tail = NULL;
    }
        void push(int val){
            Node *cur = new Node(val);
            if (head == NULL)
            {
                head = cur;
                head = tail = cur;
            }
            else{
                tail->next = cur;
                tail = cur;
            }
    }

    int maxSum(){
        int sum = 0;
        int max = INT32_MIN;
        Node *cur = head;
        while(cur!=NULL){
            sum+=  cur->val;
            if(sum > max)max = sum;
            if(sum < 0)sum = 0;
            cur = cur->next;
        }

        return max;
    }
};
int main()
{
    int n;
    cin >> n;
    linkeList ll;

    while(n--){
        int x; cin >> x;
        ll.push(x);
    }

   
    cout << ll.maxSum();

}