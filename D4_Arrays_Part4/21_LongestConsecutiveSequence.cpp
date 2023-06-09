#include<bits/stdc++.h>
using namespace std;

// Brute Force - 2 Loops
// sort the array
// count the precedence
int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n) {
    if(nums.size() == 0 ){
        return 0;
    }
    
    sort(nums.begin(),nums.end());
    
    int ans = 1;
    int prev = nums[0];
    int cur = 1;
    
    for(int i = 1;i < nums.size();i++){
        if(nums[i] == prev+1){
            cur++;
        }
        else if(nums[i] != prev){
            cur = 1;
        }
        prev = nums[i];
        ans = max(ans, cur);
    }
    return ans;
}

// Optimal Appraoch 
int longestConsecutive(vector<int>& nums){
    int n = nums.size(), res = 0;
    if(n<2) return n;
    unordered_set<int> st;

    for(int i: nums){
        st.insert(i);
    }

    for(int i : nums){
        if(st.find(i-1) != st.end()){ //it means it have its precedence
            int curr = i, len = 1;
            while(st.find(curr-1) != st.end()){
                len++;
                curr--;
            }
            res = max(res, len);
        }
    }
    return res;
}