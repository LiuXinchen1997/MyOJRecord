/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
public:
    vector<vector<int>> sums;

    NumMatrix(vector<vector<int>>& matrix) {
        if (0 == matrix.size()) { return; }
        int m = matrix.size();
        int n = matrix[0].size();
        sums = vector<vector<int>>(m, vector<int>(n, 0));

        sums[0][0] = matrix[0][0];
        for (int i = 1; i < m; i++) {
            sums[i][0] = sums[i-1][0] + matrix[i][0];
        }
        for (int i = 1; i < n; i++) {
            sums[0][i] = sums[0][i-1] + matrix[0][i];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        ans += sums[row2][col2];
        if (row1 == 0 && col1 == 0) {
            return ans;
        }
        if (row1 == 0 && col1 != 0) {
            ans -= sums[row2][col1-1];
            return ans;
        }
        if (row1 != 0 && col1 == 0) {
            ans -= sums[row1-1][col2];
            return ans;
        }

        ans -= sums[row1-1][col2];
        ans -= sums[row2][col1-1];
        ans += sums[row1-1][col1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

