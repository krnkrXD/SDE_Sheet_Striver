#include <bits/stdc++.h>
using namespace std;

// Brute Force - Using nested Loops

// Better - Using Hashing or Freq Array
pair<int,int> missingAndRepeating(vector<int> &arr, int n){
    // [1,2,3,5,6,6]
    vector<int> freq(n+1, 0);
    for(int i: arr){
        freq[i]++;
    }

    int missing = -1, repeating = -1;
    for (int i = 0; i<=n; i++){
        if(freq[i] == 0) missing = i;
        else if(freq[i] > 1) repeating = i;
        else if(missing != -1 and repeating != -1) break;
    }
    return {missing, repeating};
}

// Optimal Approach
pair<int,int> missingAndRepeating(vector<int> &arr, int n){
    // SN, S2N
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    
    // S, S2
    long long S = 0, S2 = 0;
    for(int i : arr){
        S += i;
        S2 += i * i;
    }

    // S - SN = (1)     x - y = (1)
    // S2 - S2N = (2)   x2 - y2 = (2)
    // x + y = (2)/(1)
    long long val1 = S - SN;
    long long val2 = (S2 - S2N) / val1;

    // x - y = val1
    // x + y = val2
    // x = (val1 + val2)/2 
    // y = (val2 - x)
    long long repeating = (val1 + val2) / 2;
    long long missing = (val2 - repeating);
    return {int(missing), int(repeating)};
}
