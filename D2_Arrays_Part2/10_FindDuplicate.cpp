#include <bits/stdc++.h>
using namespace std;
// Brute Force
// Sort and check i and i + 1
int findDuplicate(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 1; i++){
        if(arr[i] == arr[i+1]){
            return arr[i];
        }
    }
    return -1;
}

// Better Approach
// Frequency Arr Or Unordered_map
int findDuplicate(vector<int> &arr, int n){
    // [1,2,3,3], n = 4
    vector<int> freq(n, 0);
    for(int i : arr){
        freq[i] = 1;
    }
    for (int i = 0; i < n; i++){
        if(freq[i] > 1) return i;
    }
    return -1;
}

// Optimized Approach - LinkedList Cycle
int findDuplicate(vector<int> &arr, int n){
    int slow = arr[0], fast = arr[0];
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    fast = arr[0];
    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}