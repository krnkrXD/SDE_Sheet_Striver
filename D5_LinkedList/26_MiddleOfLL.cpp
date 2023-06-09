// Brute Force 
// store in vector, return n/2

// Better 
// Cnt Nodes, return n/2

// Optimal Approach
// slow and fast
Node *findMiddle(Node *head) {
    // Write your code here
    Node* slow = head, fast = head;
    while(fast!=NULL || fast->next != NULL){
        slow = slow -> next;
        fast = fast->next->next;
    }
    return slow;
}

