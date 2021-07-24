/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) { return 0; }
        int m = matrix.size();
        int n = matrix[0].size();

        int max_area = 0;
        vector<vector<int>> left(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') { continue; }
                left[i][j] = 1;
                if (j > 0) { left[i][j] = left[i][j-1] + 1; }

                int width = left[i][j];
                int cur_height = i;
                for (; cur_height >= 0; cur_height--) {
                    width = min(width, left[cur_height][j]);
                    max_area = max(max_area, (i-cur_height+1) * width);
                }

                int height = i - cur_height;
                max_area = max(max_area, width * height);
            }
        }

        return max_area;
    }
};
// @lc code=end

