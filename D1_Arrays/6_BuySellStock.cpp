#include <bits/stdc++.h>
using namespace std;
// Brute Force
int maximumProfit(vector<int> &prices){
    int n = prices.size();
    int res = 0;
    for (int i = 0; i < n; i++){
        int currProfit = 0;
        int currPrice = prices[i];
        for (int j = i + 1; j < n; j++){
            currProfit = max(currProfit, prices[j] - prices[i]);
        }
        res = max(res, currProfit);
    }
    return res;
}
// TC - O(N*N)
// SC - O(1)

// Better Approach
// Take Care of Minimum Price
int maximumProfit(vector<int> &prices){
    int n = prices.size();
    int maxProfit = 0, minPrice = prices[0];
    for(int price : prices){
        maxProfit = max(maxProfit, price - minPrice);
        minPrice = min(minPrice, price);
    }
    return maxProfit;
}