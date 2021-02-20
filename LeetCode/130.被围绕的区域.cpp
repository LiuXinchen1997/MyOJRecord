/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<char>>& board, int x, int y) {
        int n = board.size();
        int m = board[0].size();
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O') { return; }

        board[x][y] = 'A';
        dfs(board, x-1, y);
        dfs(board, x+1, y);
        dfs(board, x, y-1);
        dfs(board, x, y+1);
    }

    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) { return; }
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            dfs(board, i, 0);
            dfs(board, i, m-1);
        }

        for (int j = 1; j < m; j++) {
            dfs(board, 0, j);
            dfs(board, n-1, j);
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'A') { board[i][j] = 'O'; }
                else if (board[i][j] == 'O') { board[i][j] = 'X'; }
            }
        }
    }
};
// @lc code=end

