#include <bits/stdc++.h>
using namespace std; 


// Brute Force - Nested Loop
long long getInversions(long long *arr, int n){
    int count = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                count++;
            }
        }
    }
    return count;
}


// Optimal Solution - Merge Sort
long long merge(long long arr[],int temp[],int left,int mid,int right){
    int inv_count=0;
    int i = left;
    int j = mid;
    int k = left;
    while((i <= mid-1) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left ; i <= right ; i++)
        arr[i] = temp[i];
    
    return inv_count;
}

long long merge_Sort(long long arr[],int temp[],int left,int right){
    int mid,inv_count = 0;
    if(right > left){
        mid = (left + right)/2;

        inv_count += merge_Sort(arr,temp,left,mid);
        inv_count += merge_Sort(arr,temp,mid+1,right);

        inv_count += merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}

long long getInversions(long long *arr, int n){
    int temp[n];
    return merge_Sort(arr,temp,0,n-1);
}