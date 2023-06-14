#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int num;
    node* next;
    node(int val) {
        num = val;
        next = NULL;
    }
};
          
/*
INTUITION
The following steps are needed to arrive at the desired output. 
- Create a dummy node. Point next to this node to head of the linked list provided.
- Iterate through the given linked list to get the length of the list.
- Create three pointer pre,cur and nex to reverse each group. Why? If we observe output, we can see that we have to reverse each group, apart from modifying links of group.
- Iterate through the linked list until the length of list to be processed is greater than and equal to given k.
- For each iteration, point cur to pre->next and nex to nex->next.
- Start nested iteration for length of k.
- For each iteration, modify links as following steps:-
cur->next = nex->next
nex->next = pre->next
pre->next = nex
nex = cur->next
Move pre to cur and reduce length by k.
*/


//utility function to find length of the list
int lengthOfLinkedList(node* head) {
    int length = 0;
    while(head != NULL) {
        ++length;
        head = head->next;
    }
    return length;
}
//utility function to reverse k nodes in the list
node* reverseKNodes(node* head,int k) {
    if(head == NULL||head->next == NULL) return head;
    
    int length = lengthOfLinkedList(head);
    
    node* dummyHead = new node(0);
    dummyHead->next = head;
    
    node* pre = dummyHead;
    node* cur;
    node* nex;
    
    while(length >= k) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= k;
    }
    return dummyHead->next;
}

// CODESTUDIO VERSION
int lengthOfLinkedList(Node* head) {
    int length = 0;
    while(head != NULL) {
        ++length;
        head = head->next;
    }
    return length;
}
// reverse the nodes
Node *reverse(Node *head) {
    Node *p = head, *nxt, *prev = NULL;
    while (p) {
        nxt = p->next;
        p->next = prev;

        prev = p;
        p = nxt;
    }
    return prev;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	if(head == NULL||head->next == NULL) return head;
    
    int length = lengthOfLinkedList(head);
    
    Node* dummyHead = new Node(0);
    dummyHead->next = head;
    
    Node* pre = dummyHead;
    Node* cur;
    Node* nex;
    
    int j = 0;
    for(int i = 0; i<n; i++){
        if(length == 0){
            break;
        }
        if(b[i] <= length){
            cur = pre->next;
            nex = cur->next;
            if(b[i] == 0) continue;
            for(int j = 0; j<b[i]-1; j++){
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            length -= b[i];
            pre = cur;
        }
        else if(length<= b[i]){
            pre->next = reverse(pre->next);
            length = 0;
        }
    }
    return dummyHead->next;
}