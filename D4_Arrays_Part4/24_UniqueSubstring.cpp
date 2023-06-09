#include <bits/stdc++.h> 
using namespace std;

// Brute Force
// Find every substring using nested loop
// and one loop to check the uniqueness.


// Better Appraoch 
// Find every substring and parellely check the uniqueness.

// Optimal - sliding window
// take i, j ptr = 0
// move j until u counter the repeated char.
// then do while loop to move i to remove the repeated char.
int uniqueSubstrings(string input){
    int n = input.length();
    int i = 0, j = 0;
    int maxi = -1e9;
    unordered_map<char, int> mp;
    while(j<n){
        mp[input[j]]++;

        if(mp[input[j]] > 1){
            while(i < n and mp[input[j]] > 1){
                mp[input[i]] --;
                i++;
            }
        }
        maxi = max(maxi, j-i+1);
        j++;
    }
    return maxi;
}