#include<bits/stdc++.h>
using namespace std;

// BRUTE
// storing the nodes in map
// if visit the node again, return that node.

// OPTIMAL
// Fast&Slow
// when fast and slow collides, loop exists
// if it isn't collides, loop unexists
node* detectCycle(node* head) {
    if(head == NULL||head->next == NULL) return NULL;
        
    node* fast = head;
    node* slow = head;
    node* entry = head;
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
            
        if(slow == fast) {
            while(slow != entry) {
                slow = slow->next;
                entry = entry->next;
            }
            return slow;
        }
    }
    // slow and fast was never collides
    return NULL;
}