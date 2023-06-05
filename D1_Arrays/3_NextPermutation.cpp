// Brute Force
// using recursion permutation
// TC - O(N! * N)
// SC - O(1)

// Better Approach
vector<int> nextPermutation(vector<int> &nums, int n){
    next_permutation(nums.begin(),nums.end());
    return nums;
}
// TC - O(N*logN)
// SC - O(1)




// Optimized Approach
// 
vector<int> nextPermutation(vector<int> &arr, int n){
    // traverse backward, if arr[i] < arr[i+1]
    int i, j;
    for(i = n-2 ; i>=0; i--){
        if(arr[i] < arr[i+1]){
            break;
        }
    }
    if(i<0){
        reverse(arr.begin(),arr.end());
    }
    else{
        for(j = n-1; j>i; j--){
            if(arr[j]>arr[i]){
                break;
            }
        }
        swap(arr[i],arr[j]);
        reverse(arr.begin() + (i + 1), arr.end());
    }
    return arr;
}
// TC - O(3N)
// Finding the break-point, finding the next greater element, and reversal at the end takes O(N) for each, where N is the number of elements in the input array. This sums up to 3*O(N) which is approximately O(3N).
// SC - O(1)