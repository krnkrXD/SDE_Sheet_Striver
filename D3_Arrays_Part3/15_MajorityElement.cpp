#include <bits/stdc++.h>
using namespace std;

// Brute Force
// Nested Loop, select arr[i] and count freq of it in another loop.


// Better Approach
// Count the freq of each ele. Using hashing.
// Select ele of freq > n/2.


// Optimal - Moore's Voting Algorithm
int findMajorityElement(int arr[], int n) {
	int curr = arr[0];
	int cnt = 0;
	for(int i = 0; i<n; i++){
		if(cnt == 0){
			curr = arr[i];
			cnt ++;
		}
		else if(curr == arr[i]){
			cnt ++;
		}
		else{
			cnt --;
		}
	}

    // check if stored ele is the majority ele or not.
	int cnt_curr = 0;
	for(int i = 0; i<n; i++){
		if(curr == arr[i]) cnt_curr++;
	}

	if(cnt_curr > n/2) return curr;
	return -1;
}