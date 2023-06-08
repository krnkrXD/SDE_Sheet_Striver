#include<bits/stdc++.h>
using namespace std;

// Brute Force
// Nested Loop, select arr[i] and count freq of it in another loop.

// Better Approach
// Count the freq of each ele. Using hashing.
// Select ele of freq > n/3.

// Optimal - (Extended Boyer Moore’s Voting Algorithm)
vector<int> majorityElementII(vector<int> &arr){
    //cnt1 & cnt2 –  for tracking the counts of elements
    // el1 & el2 – for storing the majority of elements.
    int n = arr.size();
    int cnt1 = 0, cnt2 = 0;     // counts
    int ele1 = INT_MIN, ele2 = INT_MIN; // ele1 and ele2
    for (int i = 0; i < n; i++){
        if(cnt1 == 0 && ele2 != arr[i]){
            cnt1 = 1;
            ele1 = arr[i];
        }
        else if(cnt2 == 0 && ele1 != arr[i]){
            cnt2 = 1;
            ele2 = arr[i];
        }
        else if(arr[i] == ele1) cnt1++;
        else if(arr[i] == ele2) cnt2++;
        else{
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers
    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == ele1) cnt1++;
        if (arr[i] == ele2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(ele1);
    if (cnt2 >= mini) ls.push_back(ele2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

    return ls;
}