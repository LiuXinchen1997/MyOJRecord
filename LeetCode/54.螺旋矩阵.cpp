/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (0 == matrix.size()) { return res; }

        vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int cur_dir = 0;
        int cur_x = 0;
        int cur_y = 0;
        while (true) {
            if (0 <= cur_x && cur_x < matrix.size() && 0 <= cur_y && cur_y < matrix[0].size() && !visited[cur_x][cur_y]) {
                res.push_back(matrix[cur_x][cur_y]);
                visited[cur_x][cur_y] = 1;
            }

            bool change = false;
            int old_dir = cur_dir;
            while (cur_x + dx[cur_dir] < 0 || cur_x + dx[cur_dir] >= matrix.size()
                || cur_y + dy[cur_dir] < 0 || cur_y + dy[cur_dir] >= matrix[0].size()
                || visited[cur_x + dx[cur_dir]][cur_y + dy[cur_dir]]) {
                cur_dir = (cur_dir + 1) % 4;
                change = true;
                if (old_dir == cur_dir) { break; }
            } 
            
            if (change && cur_dir == old_dir) { break; }
            
            cur_x += dx[cur_dir];
            cur_y += dy[cur_dir];
        }

        return res;
    }
};
// @lc code=end

