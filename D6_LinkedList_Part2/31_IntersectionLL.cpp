#include<bits/stdc++.h>
using namespace std;
Node* findIntersection(Node *firstHead, Node *secondHead){
    //Write your code here
    if(firstHead == NULL || secondHead == NULL ) return NULL;
    unordered_map<Node*, int> mpp;
    while(firstHead != NULL){
        mpp[firstHead] = 1;
        firstHead = firstHead->next;
    }

    while(secondHead != NULL){
        if(mpp.find(secondHead) != mpp.end()){
            return secondHead;
        }
        secondHead = secondHead->next;
    }
    return NULL;
}

// Optimal - Length difference
int length(Node* head){
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}
Node* findIntersection(Node *firstHead, Node *secondHead){
    int l1 = length(firstHead);
    int l2 = length(secondHead);

    if(l1 < l2){
        int diff = l2 - l1;
        while(diff --){
            secondHead = secondHead->next;
        }
    }
    else if(l1 > l2){
        int diff = l1 - l2;
        while(diff --){
            firstHead = firstHead->next;
        }
    }

    while(firstHead != secondHead){
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }
    return firstHead;
}