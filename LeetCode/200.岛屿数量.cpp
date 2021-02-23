/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();

        grid[x][y] = '0';
        if (x-1 >= 0 && '1' == grid[x-1][y]) { dfs(grid, x-1, y); }
        if (x+1 < m && '1' == grid[x+1][y]) { dfs(grid, x+1, y); }
        if (y-1 >= 0 && '1' == grid[x][y-1]) { dfs(grid, x, y-1); }
        if (y+1 < n && '1' == grid[x][y+1]) { dfs(grid, x, y+1); }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (0 == m) { return 0; }
        int n = grid[0].size();
        
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ('0' == grid[i][j]) { continue; }
                count += 1;
                dfs(grid, i, j);
            }
        }

        return count;
    }
};
// @lc code=end

