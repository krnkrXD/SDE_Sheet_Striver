#include <bits/stdc++.h>

/************************************************************

Following is the linked list node structure.
template <typename T>
class Node {
    public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};
************************************************************/
    


Node<int>* sortTwoLists(Node<int>* ptr1, Node<int>* ptr2){
    if(ptr1 == NULL) return ptr2;
    if(ptr2 == NULL) return ptr1;
    
    Node<int> *res;
    if(ptr1->data <= ptr2->data){
        res = ptr1;
        ptr1 = ptr1->next;
    }else{
        res = ptr2;
        ptr2 = ptr2->next;
    }

    Node<int> *finalres = res;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1 -> data <= ptr2 ->data){
            res->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            res->next = ptr2;
            ptr2 = ptr2->next;
        }
        res = res->next;
    }

    if(ptr1 != NULL) res->next = ptr1;
    if(ptr2 != NULL) res->next = ptr2;
    return finalres;
}
