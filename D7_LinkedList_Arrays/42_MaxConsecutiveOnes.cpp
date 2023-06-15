#include<bits/stdc++.h>
using namespace std;

// Striver's Version
// longest seq of 1's
int longestSubSeg(vector<int> &arr , int n){
    int j = 0;
    int ones = 0, res = 0;
    while(j<n){
        if(arr[j] == 1){
            ones++;
            res = max(res, ones);
        }
        else{
            ones = 0;
        }
        j++;
    }
    return res;
}


// CodeStudio version
// longest seq continous 1's
// by replacing atmost K zeros

int longestSubSeg(vector<int> &arr , int n, int k){
    int i = 0, j = 0;
    int zeros = 0, res = 0;
    while(j<n){
        if(arr[j] == 0) zeros++;

        if(zeros>k){
            while(zeros > k){
                if(arr[i] == 0) zeros --;
                i++;
            }
        }

        res = max(res, j - i + 1);
        j++;
    }
    return res;
}
