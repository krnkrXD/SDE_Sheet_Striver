void solve(int i, int sum, vector<int>& arr, vector<int> tmp, vector<vector<int>>& res){
    if(i == arr.size()){
        if(sum == 0){
            res.push_back(tmp);
            return;
        }
        else return;
    }

    solve(i + 1, sum, arr, tmp, res);
    tmp.push_back(arr[i]);
    solve(i + 1, sum - arr[i], arr, tmp, res);
    return;
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<int> tmp;
    vector<vector<int>> res;
    solve(0, k, arr, tmp, res);
    return res;
}