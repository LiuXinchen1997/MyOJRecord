/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board, string& target, string cur,
     vector<vector<bool>>& visited, bool& res, int cur_row, int cur_col) {
        if (res) { return; }
        if (cur == target) { res = true; return; }

        int drow[4] = {1, 0, -1, 0};
        int dcol[4] = {0, 1, 0, -1};
        if (board[cur_row][cur_col] == target[cur.size()]) {
            if (cur+board[cur_row][cur_col] == target) { res = true; return; }
            
            visited[cur_row][cur_col] = true;
            for (int i = 0; i < 4; i++) {
                if (res) { return; }
                
                int tmp_row = cur_row+drow[i];
                int tmp_col = cur_col+dcol[i];
                if (tmp_row < 0 || tmp_row >= board.size()) { continue; }
                if (tmp_col < 0 || tmp_col >= board[0].size()) { continue; }
                if (visited[tmp_row][tmp_col]) { continue; }
                solve(board, target, cur+board[cur_row][cur_col], visited, res, tmp_row, tmp_col);
            }
            visited[cur_row][cur_col] = false;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        bool res = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                solve(board, word, "", visited, res, i, j);
                if (res) { return true; }
            }
        }

        return false;
    }
};
// @lc code=end

