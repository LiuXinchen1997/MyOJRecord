/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int boxes[9][9] = {0};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if ('.' == board[i][j]) { continue; }
                int num = board[i][j] - '1';
                
                if (rows[i][num]) { return false; }
                else { rows[i][num] = 1; }

                if (cols[j][num]) { return false; }
                else { cols[j][num] = 1; }

                if (boxes[(i/3)*3+j/3][num]) { return false; }
                else { boxes[(i/3)*3+j/3][num] = 1; }
            }
        }

        return true;
    }
};
// @lc code=end

