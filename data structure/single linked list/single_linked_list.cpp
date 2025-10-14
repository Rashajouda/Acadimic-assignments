#include <iostream>
#include <climits>
using namespace std;

// Node class representing a single element of the linked list
class Node
{
    int data;
    Node *ptr;

public:
    Node(int data)
    {
        this->data = data;
        this->ptr = NULL;
    }

    int get_data()
    {
        return this->data;
    }

    void set_data(int value)
    {
        this->data = value;
    }

    void set_ptr(Node *ptr)
    {
        this->ptr = ptr;
    }

    Node *get_ptr()
    {
        return this->ptr;
    }
};

// Singly Linked List class
class LinkedList
{
public:
    Node *head = NULL;

    // Add node to head
    void add_to_head(int data)
    {
        Node *node = new Node(data);
        node->set_ptr(head);
        head = node;
    }

    // Add node to tail
    void add_to_tail(int value)
    {
        Node *p = new Node(value);
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            Node *current = head;
            while (current->get_ptr() != NULL)
            {
                current = current->get_ptr();
            }
            current->set_ptr(p);
        }
    }

    // Add node after a given value
    void add_after_value(int existing_value, int new_value)
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }

        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->get_data() == existing_value)
                break;
            temp = temp->get_ptr();
        }

        if (temp == NULL)
        {
            cout << "The value does not exist" << endl;
            return;
        }

        Node *new_node = new Node(new_value);
        new_node->set_ptr(temp->get_ptr());
        temp->set_ptr(new_node);
    }

    // Add node before a given value
    void add_before(int existing_value, int new_value)
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }

        if (head->get_data() == existing_value)
        {
            Node *new_node = new Node(new_value);
            new_node->set_ptr(head);
            head = new_node;
            return;
        }

        Node *temp = head;
        Node *prev = NULL;
        while (temp != NULL)
        {
            if (temp->get_data() == existing_value)
                break;
            prev = temp;
            temp = temp->get_ptr();
        }

        if (temp == NULL)
        {
            cout << "The value " << existing_value << " does not exist" << endl;
            return;
        }

        Node *new_node = new Node(new_value);
        new_node->set_ptr(temp);
        prev->set_ptr(new_node);
    }

    // Check if list is empty
    bool is_empty()
    {
        return head == NULL;
    }

    // Find maximum value
    int find_max()
    {
        if (is_empty())
            return INT_MIN;

        int mx = INT_MIN;
        Node *temp = head;
        while (temp != NULL)
        {
            mx = max(mx, temp->get_data());
            temp = temp->get_ptr();
        }
        return mx;
    }

    // Find minimum value
    int find_min()
    {
        if (is_empty())
            return INT_MAX;

        int mn = INT_MAX;
        Node *temp = head;
        while (temp != NULL)
        {
            mn = min(mn, temp->get_data());
            temp = temp->get_ptr();
        }
        return mn;
    }

    // Find position of a value (1-based)
    int find_position_number(int n)
    {
        int pos = 1;
        Node *temp = head;
        while (temp != NULL)
        {
            if (n == temp->get_data())
                return pos;
            pos++;
            temp = temp->get_ptr();
        }
        return -1;
    }

    // Count nodes in the list
    int count_nodes()
    {
        int cnt = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            cnt++;
            temp = temp->get_ptr();
        }
        return cnt;
    }

    // Delete node at a specific position
    void del_at(int position)
    {
        if (head == NULL)
            return;

        if (position == 1)
        {
            Node *temp = head;
            head = head->get_ptr();
            delete temp;
            return;
        }

        int pos = 1;
        Node *temp = head;
        Node *before_temp = NULL;

        while (temp != NULL && pos < position)
        {
            before_temp = temp;
            temp = temp->get_ptr();
            pos++;
        }

        if (temp == NULL)
            return;

        before_temp->set_ptr(temp->get_ptr());
        delete temp;
    }

    // Delete node after a given value
    void del_after(int value)
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }

        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->get_data() == value)
                break;
            temp = temp->get_ptr();
        }

        if (temp == NULL)
        {
            cout << "The value does not exist" << endl;
            return;
        }

        if (temp->get_ptr() == NULL)
        {
            cout << "There is no node after this value" << endl;
            return;
        }

        Node *node_to_delete = temp->get_ptr();
        temp->set_ptr(node_to_delete->get_ptr());
        delete node_to_delete;
    }

    // Delete node before a given value
    void del_before(int value)
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }

        if (head->get_data() == value)
        {
            cout << "There is no node before the value" << endl;
            return;
        }

        if (head->get_ptr() != NULL && head->get_ptr()->get_data() == value)
        {
            Node *temp = head;
            head = head->get_ptr();
            delete temp;
            return;
        }

        Node *temp = head;
        Node *before_temp = NULL;
        Node *before_before_temp = NULL;

        while (temp != NULL && temp->get_data() != value)
        {
            before_before_temp = before_temp;
            before_temp = temp;
            temp = temp->get_ptr();
        }

        if (temp == NULL)
        {
            cout << "Value " << value << " not found in the list" << endl;
            return;
        }

        before_before_temp->set_ptr(temp);
        delete before_temp;
    }

    // Delete a node by value
    void delete_value(int value)
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }

        if (head->get_data() == value)
        {
            Node *temp = head;
            head = head->get_ptr();
            delete temp;
            return;
        }

        Node *temp = head;
        Node *prev = NULL;

        while (temp != NULL && temp->get_data() != value)
        {
            prev = temp;
            temp = temp->get_ptr();
        }

        if (temp == NULL)
        {
            cout << "The value is not found" << endl;
            return;
        }

        prev->set_ptr(temp->get_ptr());
        delete temp;
    }

    // Delete node from tail
    void delete_from_tail()
    {
        if (head == NULL)
            return;

        if (head->get_ptr() == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node *p = head, *q;
        while (p->get_ptr() != NULL)
        {
            q = p;
            p = p->get_ptr();
        }
        q->set_ptr(NULL);
        delete p;
    }

    // Update node at a given position
    void update(int position, int new_value)
    {
        if (head == NULL)
            return;

        int pos = 1;
        Node *temp = head;

        while (temp != NULL && pos < position)
        {
            temp = temp->get_ptr();
            pos++;
        }

        if (temp == NULL)
        {
            cout << "The position was not found" << endl;
            return;
        }

        temp->set_data(new_value);
    }

    // Copy the linked list into another list
    void copy_list(LinkedList &l2)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            l2.add_to_tail(temp->get_data());
            temp = temp->get_ptr();
        }
    }

    // Print the linked list
    void print_linked_list()
    {
        if (is_empty())
        {
            cout << "Linked list is empty\n";
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->get_data() << " ";
            temp = temp->get_ptr();
        }
        cout << "\n";
    }

    // Destructor to free memory
    ~LinkedList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            temp = head->get_ptr();
            delete head;
            head = temp;
        }
    }
};

int main()
{
    LinkedList l, l2;
    l.add_to_head(4);
    l.add_to_head(8);
    l.add_to_tail(100);

    cout << "This is l1\n";
    l.print_linked_list();

    l.copy_list(l2);
    cout << "This is l2\n";
    l2.print_linked_list();
}
