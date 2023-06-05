#include <bits/stdc++.h> 

// Brute Force
// Use any sorting algorithm
// TC - O(NLogN)
// SC - O(1)


// Better Approach
// Count 0, 1 and 2
// TC - O(2N)
// SC - O(3)


// Optimized (Dutch National Flag)
// [0.....low-1] -> 0
// [low...mid-1] -> 1
// [high+1..n-1] -> 2
// [mid....high] -> random 012
void sort012(int *arr, int n){
    int low = 0, mid = 0, high = n - 1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            mid++; low++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else if(arr[mid] == 2){
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
// TC - O(N)
// SC - O(3)