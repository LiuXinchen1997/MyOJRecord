/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j1 = 0, j2 = A[0].size() - 1; j1 < j2; j1++, j2--) {
                swap(A[i][j1], A[i][j2]);
            }
        }

        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[0].size(); j++) {
                if (A[i][j] == 0) { A[i][j] = 1; }
                else if (A[i][j] == 1) { A[i][j] = 0; }
            }
        }

        return A;
    }
};
// @lc code=end

