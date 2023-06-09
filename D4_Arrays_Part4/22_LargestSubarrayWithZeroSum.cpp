#include<bits/stdc++.h>
using namespace std;

// Brute Force 
// find all the subarrays and calculate the sum
// if sum == 0, calc size and store the max.


// Optimal Approach - Using hashing store the previous sum
// if prev sum occurs again it means there is a subarray whose sum is zero.
int maxLen(vector<int>&arr, int n){
    unordered_map<int, int> mp;
    int sum = 0, maxi = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
        if(sum == 0){
            maxi = i + 1;
        }
        else{
            if(mp.find(sum) != mp.end()){
                maxi = max(maxi, i - mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }
    }
    return maxi;
}