#include<bits/stdc++.h>
using namespace std;

// Striver's Version
// sum == 0
vector<vector<int>> threeSum(vector<int>& num) {
    vector<vector<int>> res; 
    sort(num.begin(), num.end()); 
    
    // [a + b + c]
    for (int i = 0; i < (int)(num.size()) - 2; i++){        // a
        if (i == 0 || (i > 0 && num[i] != num[i-1])) {
            // 2 Pointer - [b , c]
            int low = i + 1, high = (int)(num.size()) - 1, sum = 0 - num[i];
            while (low < high) {
                if (num[low] + num[high] == sum) {
                    vector<int> temp; 
                    temp.push_back(num[i]); 
                    temp.push_back(num[low]); 
                    temp.push_back(num[high]); 
                    res.push_back(temp);
                    
                    while (low < high && num[low] == num[low+1]) low++;
                    while (low < high && num[high] == num[high-1]) high--;
                    low++; high--;
                } 
                else if (num[low] + num[high] < sum) low++;
                else high--;
            }
        }
    }
    return res;
}

// Codestudio version
// sum == k
#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>num, int n, int k) {
	// Write your code here.
	vector<vector<int>> res; 
    sort(num.begin(), num.end()); 
    
    // [a + b + c]
    for (int i = 0; i < (int)(num.size()) - 2; i++){        // a
        if (i == 0 || (i > 0 && num[i] != num[i-1])) {
            // 2 Pointer - [b , c]
            int low = i + 1, high = (int)(num.size()) - 1, sum = k - num[i];
            while (low < high) {
                if (num[low] + num[high] == sum) {
                    vector<int> temp; 
                    temp.push_back(num[i]); 
                    temp.push_back(num[low]); 
                    temp.push_back(num[high]); 
                    res.push_back(temp);
                    
                    while (low < high && num[low] == num[low+1]) low++;
                    while (low < high && num[high] == num[high-1]) high--;
                    low++; high--;
                } 
                else if (num[low] + num[high] < sum) low++;
                else high--;
            }
        }
    }
    return res;
}