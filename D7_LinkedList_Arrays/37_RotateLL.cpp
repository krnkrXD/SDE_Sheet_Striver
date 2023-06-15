#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

Node* rotateRight(Node* head,int k) {
    if(head == NULL||head->next == NULL) return head;
    for(int i=0;i<k;i++) {
        Node* temp = head;
        while(temp->next->next != NULL) // till last-second node
            temp = temp->next;
        
        Node* end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}