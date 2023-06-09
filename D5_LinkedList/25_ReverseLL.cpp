#include <bits/stdc++.h>
using namespace std;
/****************************************************************

    Following is the class structure of the LinkedListNode class:
*****************************************************************/

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};


// Brute Force
// Make an array to store the values of Linkedlist.
// Then reverse it, and change the values of Linkedlist.

// Better Approach
// Using Recursive Method to reverse

// Optimal - Using three ptr
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *next;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}