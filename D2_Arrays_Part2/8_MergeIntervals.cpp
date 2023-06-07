#include <bits/stdc++.h>
using namespace std;
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    vector<int> curr = {intervals[0][0], intervals[0][1]};
    for(auto it : intervals){
        if(it[0] <= curr[1]){  // itervals can be merged
            curr = {curr[0], max(it[1], curr[1])};
        }
        else{
            ans.push_back(curr);
            curr = it;
        }
    }
    ans.push_back(curr);
    return ans;
}
