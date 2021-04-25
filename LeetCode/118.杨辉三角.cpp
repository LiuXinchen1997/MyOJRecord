/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 1; i <= numRows; i++) {
            vector<int> row(i, 1);
            for (int j = 1; j <= i-2; j++) {
                row[j] = res[i-2][j-1] + res[i-2][j];
            }
            res.emplace_back(row);
        }

        return res;
    }
};
// @lc code=end

