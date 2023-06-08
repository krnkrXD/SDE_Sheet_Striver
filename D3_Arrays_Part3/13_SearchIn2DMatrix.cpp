#include<bits/stdc++.h>
using namespace std;
// brute force
// search in every row bcz every row is sorted
// apply binary search in row


// Optimal Approach
// Start searching from top - right cell. and move accordingly
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int j = mat[0].size()-1, i = 0;
    while(i<mat.size() and j >= 0){
        if(mat[i][j] == target) return true;
        else if(mat[i][j] < target) i ++;
        else if(mat[i][j] > target) j --;
    }
    return false;
}