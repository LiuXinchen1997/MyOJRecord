/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (0 == matrix.size()) { return false; }

        int m = matrix.size();
        int n = matrix[0].size();
        // m*n; // [0, mn-1]
        int l = 0, r = m*n-1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int row_m = mid / n;
            int col_m = mid % n;
            if (matrix[row_m][col_m] == target) { return true; }
            else if (matrix[row_m][col_m] > target) { r = mid - 1; }
            else { l = mid + 1; }
        }

        return false;
    }
};
// @lc code=end

