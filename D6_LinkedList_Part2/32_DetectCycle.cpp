// Brute - store the visited node in map.
// check for every node, that it is visited before or not.

// Optimal - fast and slow ptr
bool detectCycle(Node *head){
    if (head == NULL || head->next == NULL) 
        return false;
    
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}