#include <bits/stdc++.h>
using namespace std;

// Node class representing a single element of the linked list

class Node
{
    int data;
    Node *prev, *next;

public:
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    // Getter for node data
    int get_data()
    {
        return this->data;
    }

    // Setter for node data
    void set_data(int value)
    {
        this->data = value;
    }

    // Setter for previous pointer
    void set_prev_node(Node *prev)
    {
        this->prev = prev;
    }

    // Getter for previous pointer
    Node *get_prev_node()
    {
        return this->prev;
    }

    // Setter for next pointer
    void set_next_node(Node *next)
    {
        this->next = next;
    }

    // Getter for next pointer
    Node *get_next_node()
    {
        return this->next;
    }
};

// Double Linked List class

class DoubleLinkedList
{
    Node *head;

public:
    // Constructor initializes list as empty
    DoubleLinkedList() { head = NULL; }

    /*
        Add a new node at the head of the list.
    */
    void add_to_head(int data)
    {
        Node *new_node = new Node(data);

        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            new_node->set_next_node(head);
            head->set_prev_node(new_node);
            head = new_node;
        }
    }

    /*
        Add a new node at the tail of the list.
    */
    void add_to_tail(int data)
    {
        Node *new_node = new Node(data);

        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            Node *temp = head;

            while (temp->get_next_node() != NULL)
            {
                temp = temp->get_next_node();
            }

            temp->set_next_node(new_node);
            new_node->set_prev_node(temp);
        }
    }

    /*
        Insert a new node AFTER a node with specific value.
        If value is not found → print message.
    */
    void insert_after_value(int data, int value)
    {
        if (is_empty())
        {
            cout << "List is empty";
            return;
        }

        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->get_data() == value)
            {
                Node *new_node = new Node(data);

                new_node->set_prev_node(temp);
                new_node->set_next_node(temp->get_next_node());

                if (temp->get_next_node() != NULL)
                {
                    temp->get_next_node()->set_prev_node(new_node);
                }

                temp->set_next_node(new_node);
                return;
            }

            temp = temp->get_next_node();
        }

        cout << "The value was not found";
    }

    // Check if list is empty
    bool is_empty()
    {
        return head == NULL;
    }

    /*
        Find a node by value.
        Returns its position (1-based).
        If not found → returns -1.
    */
    int find_node(int data)
    {
        if (is_empty())
        {
            cout << "List is empty";
            return -1;
        }

        Node *temp = head;
        int cnt = 1;

        while (temp != NULL)
        {
            if (temp->get_data() == data)
                return cnt;

            temp = temp->get_next_node();
            cnt++;
        }

        cout << "The value was not found";
        return -1;
    }

    /*
        Print all elements in the list.
    */
    void print_list()
    {
        Node *temp = head;

        if (is_empty())
        {
            cout << "List is empty";
            return;
        }

        while (temp != NULL)
        {
            cout << temp->get_data() << " ";
            temp = temp->get_next_node();
        }
        cout << endl;
    }

    /*
        Delete node from the head.
    */
    void delete_from_head()
    {
        if (is_empty())
        {
            cout << "List is empty";
            return;
        }
        else if (head->get_next_node() == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->get_next_node();
            head->set_prev_node(NULL);
            delete temp;
        }
    }

    /*
        Delete node from the tail.
    */
    void delete_from_tail()
    {
        if (is_empty())
        {
            cout << "List is empty";
            return;
        }
        else if (head->get_next_node() == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *temp = head;

            while (temp->get_next_node() != NULL)
            {
                temp = temp->get_next_node();
            }

            temp->get_prev_node()->set_next_node(NULL);
            delete temp;
        }
    }

    /*
        Delete any node by value.
    */
    void delete_any_node(int data)
    {
        if (is_empty())
        {
            cout << "List is empty";
            return;
        }

        if (head->get_data() == data)
        {
            delete_from_head();
            return;
        }

        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->get_data() == data)
            {
                if (temp->get_next_node() == NULL)
                {
                    temp->get_prev_node()->set_next_node(NULL);
                }
                else
                {
                    temp->get_prev_node()->set_next_node(temp->get_next_node());
                    temp->get_next_node()->set_prev_node(temp->get_prev_node());
                }

                delete temp;
                return;
            }

            temp = temp->get_next_node();
        }

        cout << "Value not found";
    }

    /*
        Reverse the entire doubly linked list.
    */
    void reverse()
    {
        if (is_empty())
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->get_next_node() == NULL)
        {
            cout << "List has only one element" << endl;
            return;
        }

        Node *current = head;
        Node *temp = NULL;
        Node *new_head = NULL;

        while (current != NULL)
        {
            temp = current->get_next_node();

            current->set_next_node(current->get_prev_node());
            current->set_prev_node(temp);

            new_head = current;

            current = temp;
        }

        head = new_head;
    }

    // Destructor releases all allocated memory
    ~DoubleLinkedList()
    {
        Node *temp = head;

        while (head != NULL)
        {
            head = head->get_next_node();
            delete temp;
            temp = head;
        }
    }
};

int main()
{
    DoubleLinkedList list;

    list.add_to_tail(1);
    list.add_to_tail(2);
    list.add_to_tail(3);
    list.add_to_tail(4);
    list.add_to_tail(5);

    cout << "Original list: ";
    list.print_list();

    list.reverse();

    cout << "Reversed list: ";
    list.print_list();

    return 0;
}
