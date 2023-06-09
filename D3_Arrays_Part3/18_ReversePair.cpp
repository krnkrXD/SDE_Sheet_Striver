#include <bits/stdc++.h> 
using namespace std;

// Brute Force
// Nested Loops.



// Optimal Solution
// Merge Sort
// 1 4 7    2 6 9
// if(7 > 6) then 6 and less than 6 values are counted. so add mid - i + 1
void merge(vector<int>& arr, int start, int mid, int end, int& count){
    int i = start, j = mid+1;
    while(i <= mid and j <=end){
        if(arr[i] > (long long)2*arr[j]){
            count += (mid-i+1);
            j++;
        }
        else{
            i++;
        }
    }

    sort(arr.begin()+start, arr.begin()+end+1);
}
void mergesort(vector<int>& arr,int l, int h, int& count){
    if(l>=h)
        return;
    
    int mid = (l+h)/2;
    mergesort(arr,l,mid, count);
    mergesort(arr,mid+1,h, count);
    merge(arr,l,mid,h, count);
    return;
}
int reversePairs(vector<int> &arr, int n){
    int count = 0;
	mergesort(arr, 0, n-1, count);
    return count;
}