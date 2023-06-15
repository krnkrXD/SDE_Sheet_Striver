#include <bits/stdc++.h>
using namespace std;

// Better Approach
// Using prefix and suffix
long getTrappedWater(long *arr, int n){
    long pre[n], suff[n];
    pre[0] = arr[0];
    for(int i = 1; i<n; i++){
        pre[i] = max(pre[i-1], arr[i]);
    }

    suff[n-1] = arr[n-1];
    for(int i = n-2; i>=0; i--){
        suff[i] = max(suff[i+1], arr[i]);
    }

    long ans = 0;
    for(int i = 0; i<n; i++){
        ans += min(pre[i], suff[i]) - arr[i];
    }
    return ans;
}

// Optimized
// Using 2 Pointers
int trap(vector < int > & height) {
    int n = height.size();
    int left = 0, right = n - 1;
    int res = 0;
    int maxLeft = 0, maxRight = 0;
    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= maxLeft) {
                maxLeft = height[left];
            } 
            else {
                res += maxLeft - height[left];
            }
            left++;
        } 
        else {
            if (height[right] >= maxRight) {
                maxRight = height[right];
            } else {
                res += maxRight - height[right];
            }
            right--;
        }
    }
    return res;
}