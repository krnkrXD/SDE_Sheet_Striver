#include<bits/stdc++.h>
using namespace std;

// BRUTE - store the LL in array
// - traverse till N/2 and check for palindrome.

// OPTIMIZED
// Find the middle element of the linked list
// Reverse a linked list from the next element of the middle element
// Iterate until the middle element reaches the end of the list
node* reverse(node* ptr) {
    node* pre=NULL;
    node* nex=NULL;
    while(ptr!=NULL) {
        nex = ptr->next;
        ptr->next = pre;
        pre=ptr;
        ptr=nex;
    }
    return pre;
}

bool isPalindrome(node* head) {
    if(head==NULL||head->next==NULL) return true;
        
    node* slow = head;
    node* fast = head;
        
    while(fast->next!=NULL&&fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow == middle element 
    slow->next = reverse(slow->next);
    slow = slow->next;
    node* dummy = head;
        
    while(slow!=NULL) {
        if(dummy->num != slow->num) return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;
}