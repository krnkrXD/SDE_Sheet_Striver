// Brute Force
// Traverse the mtx, if arr[i][j] == 0, make ith row and jth col = -1, except the case when ith row or jth col contains 0 dont change it.
void setZeros(vector<vector<int>> &mat){
	int n = mat.size(), m = mat[0].size();
    for(int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            if(mat[i][j] == 0){
                // jth column
                for (int k = 0; k<n; k++){
                    mat[k][j] = mat[k][j] == 0 ? mat[k][j] : -1;
                }
                // ith row
                for (int k = 0; k < m; k++){
                    mat[i][k] = mat[i][k] == 0 ? mat[i][k] : -1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j<m; j++){
            if(mat[i][j] == -1) mat[i][j] = 0;
        }
    }
}
// TC - O(N*M*(N+M))
// SC - O(1)





// Better Approach
// using 2 dummy arrays row and col if ith row and jth col cell of mtx contain 0. make row[i] and col[j] = 0 which has the bydefault val 1.
void setZeros(vector<vector<int>> &mat){
	int n = mat.size(), m = mat[0].size();
    vector<int> row(n, 1);
    vector<int> col(m, 1);
    for(int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            if(mat[i][j] == 0){
                row[i] = 0;
                col[j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j<m; j++){
            if(row[i] == 0 || col[j] == 0)
                mat[i][j] = 0;
        }
    }
}
// TC - O(N*M)
// SC - O(N+M)





// Optimized
// instead of using two arrays, consider (first row) arr[0][j] as col array and (first column) arr[i][0] as row array. 
// remember: Col0 variable
void setZeros(vector<vector<int>> &mat){
	int n = mat.size(), m = mat[0].size();
    int col0 = 1;
    for(int i = 0; i<n; i++){
        if(mat[i][0] == 0) col0 = 0;
        for (int j = 1; j<m; j++){
            if(mat[i][j] == 0){
                mat[0][j] = 0;
                mat[i][0] = 0;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--){
        // exclude the first col
        for (int j = m - 1; j >= 1; j--){
            if(mat[i][0] == 0 || mat[0][j] == 0){
                mat[i][j] = 0;
            }
        }
        // consider first col
        if(col0 == 0) mat[i][0] = 0;
    }
}
// TC - O(N*M)
// SC - O(1)

// https://leetcode.com/problems/set-matrix-zeroes/