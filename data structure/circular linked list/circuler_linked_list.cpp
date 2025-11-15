#include <bits/stdc++.h>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    // Set value of node
    void set_data(int data)
    {
        this->data = data;
    }

    // Get value of node
    int get_data()
    {
        return this->data;
    }

    // Set next pointer
    void set_next_node(Node *next)
    {
        this->next = next;
    }

    // Get next pointer
    Node *get_next_node()
    {
        return this->next;
    }
};

class CircularLinkedList
{
    Node *head;
    Node *tail;

public:
    // Constructor: initialize empty list
    CircularLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    // Check if list is empty
    bool is_empty()
    {
        return head == NULL;
    }

    // Add new node at the head of the list
    void add_to_head(int data)
    {
        Node *p = new Node;
        p->set_data(data);

        if (is_empty())
        {
            head = tail = p;
            tail->set_next_node(head);
        }
        else
        {
            Node *curr = head;
            while (curr->get_next_node() != head)
                curr = curr->get_next_node();

            p->set_next_node(head);
            head = p;
            curr->set_next_node(head);
        }
    }

    // Insert node after a specific value
    void insert_after(int val, int data)
    {
        if (is_empty()) return;

        Node *curr = head;
        do
        {
            if (curr->get_data() == val)
            {
                Node *p = new Node;
                p->set_data(data);
                p->set_next_node(curr->get_next_node());
                curr->set_next_node(p);

                if (curr == tail) tail = p;
                return;
            }
            curr = curr->get_next_node();
        } while (curr != head);
    }

    // Add node to the tail of the list
    void add_to_tail(int data)
    {
        Node *p = new Node;
        p->set_data(data);

        if (is_empty())
        {
            head = tail = p;
            tail->set_next_node(head);
        }
        else
        {
            Node *curr = head;
            while (curr->get_next_node() != head)
                curr = curr->get_next_node();

            curr->set_next_node(p);
            tail = p;
            tail->set_next_node(head);
        }
    }

    // Print all nodes in the list
    void print_list()
    {
        if (is_empty())
        {
            cout << "List is Empty\n";
            return;
        }

        Node *curr = head;
        while (curr->get_next_node() != head)
        {
            cout << curr->get_data() << " ";
            curr = curr->get_next_node();
        }
        cout << curr->get_data() << '\n';
    }

    // Find position of value in list
    int find_node(int val)
    {
        if (is_empty()) return -1;

        Node *curr = head;
        int pos = 1;

        do
        {
            if (curr->get_data() == val)
                return pos;
            curr = curr->get_next_node();
            pos++;
        } while (curr != head);

        return -1;
    }

    // Count total nodes in list
    int count_list()
    {
        if (is_empty()) return 0;

        Node *curr = head;
        int count = 0;

        do
        {
            count++;
            curr = curr->get_next_node();
        } while (curr != head);

        return count;
    }

    // Delete the head node
    void delete_from_head()
    {
        if (is_empty()) return;

        if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->get_next_node();
            delete temp;
            tail->set_next_node(head);
        }
    }

    // Delete node at specific position
    void delete_node(int pos)
    {
        if (is_empty()) return;

        int n = count_list();
        if (pos < 1 || pos > n) return;

        if (pos == 1)
        {
            delete_from_head();
            return;
        }

        Node *curr = head, *prev = NULL;

        for (int i = 1; i < pos; i++)
        {
            prev = curr;
            curr = curr->get_next_node();
        }

        prev->set_next_node(curr->get_next_node());
        if (curr == tail) tail = prev;

        delete curr;
    }

    // Delete node from tail
    void delete_from_tail()
    {
        if (is_empty()) return;

        if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *prev = head;
            while (prev->get_next_node() != head)
                prev = prev->get_next_node();

            delete tail;
            tail = prev;
            tail->set_next_node(head);
        }
    }

    // Destructor: free all memory
    ~CircularLinkedList()
    {
        if (is_empty()) return;

        if (head == tail)
        {
            delete head;
            return;
        }

        Node *curr = head->get_next_node();
        while (curr != head)
        {
            Node *next = curr->get_next_node();
            delete curr;
            curr = next;
        }

        delete head;
        head = tail = NULL;
    }
};
