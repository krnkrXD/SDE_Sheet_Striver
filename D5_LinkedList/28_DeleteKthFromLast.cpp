/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

// Brute 
// one loop to count the node
// second to return n-ith node

// Optimal 2 pointers
Node* removeKthNode(Node* head, int n){
    Node *dummy = new Node(-1);
    dummy->next = head;
    Node *fast = dummy;
    for (int i = 0; i < n; i++){
        fast = fast->next;
    }


    Node *slow = dummy;
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    return dummy->next;
}