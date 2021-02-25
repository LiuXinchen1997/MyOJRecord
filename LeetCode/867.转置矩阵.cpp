/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (0 == m) { return vector<vector<int>>(); }
        int n = matrix[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][i] = matrix[i][j];
            }
        }

        return res;
    }
};
// @lc code=end

