#define ll long long int
vector<vector<ll>> printPascal(int n) {
    vector<vector<ll>> ans(n);
    for (int i = 0; i < n; i++){
        ans[i].resize(i + 1);
        ans[i][0] = ans[i][i] = 1;
        for (int j = 1; j < i; j++){
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j]; // prevrowprevcol+prevrowsamecol
        }
    }
    return ans;
}
// TC - O(N*N)
// SC - O(1)