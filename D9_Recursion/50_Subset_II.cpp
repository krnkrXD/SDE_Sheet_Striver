#include <bits/stdc++.h> 
void solve(int i, vector<int>& arr, int n, vector<int> curr, set<vector<int>>& st){
    if(i == n){
        sort(curr.begin(), curr.end());
        st.insert(curr);
        return;
    }
    solve(i + 1, arr, n, curr, st);
    curr.push_back(arr[i]);
    solve(i + 1, arr, n, curr, st);
    return;
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr){
    // Write your code here.
    set<vector<int>> st;
    vector<int> curr;
    solve(0, arr, n, curr, st);
    vector<vector<int>> res;
    for(auto it : st){
        // if(it.size()!=0){
            res.push_back(it);
        // }
    }
    return res;
}