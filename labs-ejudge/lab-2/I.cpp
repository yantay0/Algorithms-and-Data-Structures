#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string bookName;
    Node *next;

    Node(string name)
    {
        bookName = name;
        next = nullptr;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void add_front(string s)
    {
        Node *book = new Node(s);
        book->next = head;
        head = book;
        cout << "ok\n";
    }

    void add_back(string s)
    {
        Node *book = new Node(s);
        if (head == nullptr)
        {
            head = book;
        }
        else
        {
            Node *cur = head;
            while (cur)
            {
                if (cur->next == nullptr)
                {
                    cur->next = book;
                    break;
                }
                cur = cur->next;
            }
        }
        cout << "ok\n";
    }

    void erase_front()
    {
        if (head == nullptr)
        {
            cout << "error\n";
            return;
        }
        cout << head->bookName << endl;
        head = head->next;
    }

    void erase_back()
    {
        if (head == nullptr)
        {
            cout << "error\n";
            return;
        }
        if (head->next == nullptr)
        {
            cout << head->bookName << endl;
            head = nullptr;
            return;
        }
        Node *cur = head;
        while (cur)
        {
            if (cur->next == nullptr)
            {
                cout << cur->bookName << endl;
                cur = nullptr;
                break;
            }
            cur = cur->next;
        }
    }

    void front()
    {
        if (head == nullptr)
        {
            cout << "error\n";
            return;
        }
        cout << head->bookName << endl;
    }

    void back()
    {
        if (head == nullptr)
        {
            cout << "error\n";
            return;
        }
        Node *cur = head;
        while (cur)
        {
            if (cur->next == nullptr)
            {
                cout << cur->bookName << endl;
                break;
            }
            cur = cur->next;
        }
    }

    void clear()
    {
        head = nullptr;
        cout << "ok" << endl;
    }

    void print()
    {
        Node *cur = head;
        while (cur)
        {
            cout << cur->bookName << " ";
            cur = cur->next;
        }
    }
};

int main()
{
    string s;
    LinkedList books;

    while (1)
    {
        cin >> s;
        if (s == "add_front")
        {
            string book;
            cin >> book;
            books.add_front(book);
        }
        if (s == "front")
        {
            books.front();
        }
        if (s == "add_back")
        {
            string book;
            cin >> book;
            books.add_back(book);
        }
        if (s == "back")
        {
            books.back();
        }
        if (s == "clear")
        {
            books.clear();
        }
        if (s == "erase_front")
        {
            books.erase_front();
        }
        if (s == "erase_back")
        {
            books.erase_back();
        }
        if (s == "exit")
        {
            cout << "goodbye\n";
            break;
        }
        if (s == "print")
        {
            books.print();
        }
    }
}