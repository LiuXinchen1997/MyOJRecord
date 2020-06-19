/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (0 == n) { return {}; }
        vector<vector<int> > res(n, vector<int>(n, 0));

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        int cur_x = 0, cur_y = 0;
        int cur_dir = 0;
        for (int num = 1; num <= n*n; num++) {
            res[cur_x][cur_y] = num;

            int next_x = cur_x + dx[cur_dir];
            int next_y = cur_y + dy[cur_dir];
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n
            || res[next_x][next_y]) {
                cur_dir = (cur_dir + 1) % 4;
            }

            cur_x += dx[cur_dir];
            cur_y += dy[cur_dir];
        }

        return res;
    }
};
// @lc code=end

