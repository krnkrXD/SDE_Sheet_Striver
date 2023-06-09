#include <bits/stdc++.h>
using namespace std;
int subarraysXor(vector<int> &arr, int k){
    int cnt = 0, xr = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for(int i : arr){
        xr ^= i;

        //By formula: x = xr^k:
        int x = xr ^ k;
        
        cnt += mp[x];
        mp[xr]++;
    }
    return cnt;
}