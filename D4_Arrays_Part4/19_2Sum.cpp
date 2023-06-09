#include <bits/stdc++.h>
using namespace std;
// Brute Force
// 2 Nested Loop, one is for arr[i] and second one is for arr[j],
// if arr[i] + arr[j] == target, return or store.

// Using hashing as below

// CodeStudio Version.
// Have to store all the pairs sum eql to target.
vector<vector<int>> pairSum(vector<int> &arr, int target){
    unordered_map<int, int> mp;
    vector<vector<int>> res;
    for(int i: arr){
        if(mp.find(target - i) != mp.end()){
            for(int freq = 0; freq < mp[target - i]; freq++){
                if(i >= target - i){
                res.push_back({target - i, i});
                }
                else{
                res.push_back({i, target - i});
                }
            }
        }
        mp[i]++;
    }
    sort(res.begin(), res.end());
    return res;
}

// Optimal - 2 Pointers
// arr must be sorted for this algo
pair<int,int> twoSum(vector<int>& arr, int target){
    int n = arr.size();
    int low = 0, high = n - 1;
    while(low < high){
        if(arr[low] + arr[high] == target){
            return {arr[low], arr[high]};
        }
        else if(arr[low] + arr[high] < target){
            low++;
        }
        else{
            high--;
        }
    }
    return {-1, -1};
}