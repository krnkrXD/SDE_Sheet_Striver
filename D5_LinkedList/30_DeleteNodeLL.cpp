#include <bits/stdc++.h>
// idea here is instead of deleting a current node.
// copy the data of next node and delete the next node.
// apply the deletion steps on nextnode.
void deleteNode(LinkedListNode<int> * node) {
    node->data = node->next->data;
    LinkedListNode<int>* nxtnode = node->next;
    node->next = node->next->next;
    delete nxtnode;
}