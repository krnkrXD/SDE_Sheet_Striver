#include <bits/stdc++.h>
using namespace std;
// Codestudio version where
// nums1 : [1,4,8,0,0,0]
// nums2 : [2,6,7]
vector<int> ninjaAndSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while(i >= 0 and j >= 0) {
        if(nums1[i] < nums2[j]) {
            nums1[k--] = nums2[j--];
        }
        else {
            nums1[k--] = nums1[i--];
        }
    }
    while(j >= 0) {
        nums1[k--] = nums2[j--];
    }
    return nums1;
}

// Striver's Version where
// nums1 : [1,4,8]
// nums2 : [2,6,7]

// Brute force - Use Dummy Array
// Better Approach - Without Space
// Storing arr1 - smaller elements arr2 - greater elements
void merge2sortedarrays(vector<int>& nums1, vector<int>& nums2, int n, int m){
    int left = n - 1, right = 0;
    while(left >= 0 && right < m){
        if(nums1[left] > nums2[right]){
            swap(nums1[left], nums2[right]);
            left--, right++;
        }
        else break;
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
}
// TC - O(min(n,m)) + O(NlogN) + O(MlogM)


// Optimized Approach - Gap method(ShellSort1)
// The idea: We start comparing elements that are far from each other rather than adjacent. 
// For every pass, we calculate the gap and compare the elements towards the right of the gap. Every pass, the gap reduces to the ceiling value of dividing by 2.
int solve(arr1,arr2){
	gap = ceil of((n+m)/2) where n and m = size of arr1 and arr2.
	while(gap>0){
		i = 0, j = gap
		while(j < n+m){
			// both lies in first array
			if(j<n and arr1[i] > arr2[j])
				swap(arr1[i],arr2[j])
			
			// i - first, j - second
			if(i<n and j>=n and arr1[i] > arr2[j-n])
				swap(arr1[i],arr2[j-n])
			
			// both in second array
			if(i>=n and j>=n and arr1[i-n] > arr2[j-n])
				swap(arr1[i-n],arr2[j-n])

			i++, j++
		}

		if(gap == 1)
			gap = 0;
		else
			gap = ceil(gap/2);
	}
}