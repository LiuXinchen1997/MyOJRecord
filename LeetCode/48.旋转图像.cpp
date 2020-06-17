/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void swap(int& a, int& b, int& c, int& d) {
        // a-->b, b-->c, c-->d, d-->a
        int tmp = b;
        b = a;
        a = d;
        d = c;
        c = tmp;
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (0 == n || 1 == n) { return; }

        int epoch = n / 2;
        for (int i = 0; i < epoch; i++) {
            // matrix[i][i]; // A
            // matrix[i][n-1-i]; // B
            // matrix[n-1-i][n-1-i]; // C
            // matrix[n-1-i][i]; // D
            for (int j = 0; j < n - 2*i - 1; j++) {
                swap(matrix[i+j][i], matrix[i][n-1-i-j], 
                    matrix[n-1-i-j][n-1-i], matrix[n-1-i][i+j]);
            }
        }
    }
};
// @lc code=end

