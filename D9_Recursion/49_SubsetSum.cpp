#include <bits/stdc++.h> 
void solve(int i, vector<int>& num, vector<int>& arr, int sum){
    if(i == num.size()){
        arr.push_back(sum);
        return;
    }
    solve(i + 1, num, arr, sum + num[i]);
    solve(i + 1, num, arr, sum);
    return;
}
vector<int> subsetSum(vector<int> &num){
    vector<int> arr;
    solve(0, num, arr, 0);
    sort(arr.begin(), arr.end());
    return arr;
}