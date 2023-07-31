#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class for the circular linked list
class node
{
public:
    int data;
    node *next_node;
    node(int x)
    {
        data = x;
        next_node = NULL;
    }
};

// Function to insert a new node at the end of the circular linked list
node *insert(node *item, node *head)
{
    node *temp = head;
    // Traverse to the last node
    while (temp->next_node != head)
        temp = temp->next_node;

    // Connect the new node to the last node
    temp->next_node = item;

    // Make the new node point back to the head, forming a circular linked list
    item->next_node = head;

    // Return the updated head of the circular linked list
    return head;
}

// Function to display the elements of the circular linked list
void display(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << "  ";
        temp = temp->next_node;
    } while (temp != head);
}

// Function to find the maximum element among the next k nodes starting from the given node
int get_max(node *t, int k)
{
    int max_ = INT_MIN;
    for (int i = 0; i < k; i++)
    {
        if (t->data > max_)
            max_ = t->data;
        t = t->next_node;
    }
    return max_;
}

int main()
{
    // Input the number of nodes in the circular linked list
    int n;
    cout << "Enter the number of nodes in the circular linked list: ";
    cin >> n;

    // Input the data for the first node
    int z;
    cout << "Enter the data for the first node: ";
    cin >> z;

    // Create the first node and set it as the head
    node *head = new node(z);
    n--;
    head->next_node = head; // Circular linked list, so the head points to itself initially

    // Insert the remaining n-1 nodes to form the circular linked list
    while (n--)
    {
        int x;
        cout << "Enter data for the next node: ";
        cin >> x;
        node *item = new node(x);
        item->next_node = NULL;
        head = insert(item, head);
    }

    // Input the value of k
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    // Find the maximum of the next k nodes
    // for starting k node and store in the 'arr' vector
    node *temp = head;
    vector<int> arr(k);
    for (int i = 0; i < k; i++)
    {
        arr[i] = get_max(temp->next_node, k);
        temp = temp->next_node;
    }

    // Update each node's data [k+1 ... n]to the
    // maximum among the next k nodes
    while (temp != head)
    {
        temp->data = get_max(temp->next_node, k);
        temp = temp->next_node;
    }

    // Update to first k nodes from the values
    // strored in arr
    // Here after the earlier operations temp points at head;
    for (int i = 0; i < k; i++)
    {
        temp->data = arr[i];
        temp = temp->next_node;
    }

    // Display the circular linked list after the modifications
    cout << "The circular linked list after the modifications: ";
    display(head);

    return 0;
}
