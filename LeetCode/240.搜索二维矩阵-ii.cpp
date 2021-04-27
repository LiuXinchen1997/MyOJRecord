/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int num_row = matrix.size();
        if (0 == num_row) { return false; }
        int num_col = matrix[0].size();

        int row = 0;
        int col = num_col - 1;
        while (row < num_row && col >= 0) {
            if (matrix[row][col] == target) { return true; }
            else if (matrix[row][col] > target) { col -= 1; }
            else { row += 1; }
        }

        return false;
    }
};
// @lc code=end

