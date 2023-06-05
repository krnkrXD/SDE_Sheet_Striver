#include <bits/stdc++.h>
using namespace std;

// Brute Force
int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN;        // maximum sum
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;       // subarray = arr[i.....j]
            for (int k = i; k <= j; k++) {
                //add all the elements of subarray:
                sum += arr[k];
            }
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}
// TC - O(N*N*N)



// Better Approach
int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            // current subarray = arr[i.....j]
            //add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];
            maxi = max(maxi, sum); // getting the maximum
        }
    }
    return maxi;
}
// TC - O(N*N)



// Optimized Approach
long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > maxi) {
            maxi = sum;
        }
        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }
    // To consider the sum of the empty subarray
    // uncomment the following check:
    //if (maxi < 0) maxi = 0;
    return maxi;
}
// TC - O(N)
// Limitation of Kadane's : there must be a positive number in an array.




// Follow Up - Print the Maximum Sum Subarray
// arr = [ansstart...ansend]
long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;
    int ansStart = -1, ansEnd = -1, start = 0;
    for (int i = 0; i < n; i++) {
        if(sum == 0) start = i;
        sum += arr[i];
        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}