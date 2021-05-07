/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    void backtrace(vector<vector<string>>& res, vector<int>& queues, int row, int n, unordered_set<int>& cols, unordered_set<int>& diag1, unordered_set<int>& diag2) {
        if (row == n) {
            generate(res, queues);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (cols.count(i) || diag1.count(i-row) || diag2.count(i+row)) { continue; }
            cols.insert(i);
            diag1.insert(i-row);
            diag2.insert(i+row);
            queues[row] = i;
            backtrace(res, queues, row+1, n, cols, diag1, diag2);
            cols.erase(i);
            diag1.erase(i-row);
            diag2.erase(i+row);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        auto cols = unordered_set<int>();
        auto diag1 = unordered_set<int>();
        auto diag2 = unordered_set<int>();
        vector<int> queues(n, -1);
        backtrace(res, queues, 0, n, cols, diag1, diag2);

        return res;
    }

    void generate(vector<vector<string>>& res, vector<int>& queues) {
        int n = queues.size();
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; i++) {
            board[i][queues[i]] = 'Q';
        }
        res.emplace_back(board);
    }
};
// @lc code=end

