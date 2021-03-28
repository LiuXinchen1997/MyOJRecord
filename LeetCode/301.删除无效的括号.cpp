/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
class Solution {
public:
    set<string> set_ans;

    vector<string> removeInvalidParentheses(string s) {
        int remove_left = 0;
        int remove_right = 0;
        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                continue;
            }
            if (ch == '(') { remove_left += 1; }
            if (ch == ')') {
                if (remove_left > 0) { remove_left -= 1; }
                else { remove_right += 1; }
            }
        }

        vector<string> ans;
        if (remove_right == 0 && remove_left == 0) {
            ans.emplace_back(s);
            return ans;
        }

        dfs(0, 0, 0, remove_left, remove_right, s, "");
        return vector<string>(set_ans.begin(), set_ans.end());
    }

    void dfs(int index, int count_left, int count_right, int remove_left, int remove_right, string& s, string cur_s) {
        if (index == s.size()) {
            if (remove_left == 0 && remove_right == 0) {
                set_ans.insert(cur_s);
            }
            return;
        }

        char ch = s[index];
        // 1. remove current char
        if (ch == '(' && remove_left > 0) {
            dfs(index+1, count_left, count_right, remove_left-1, remove_right, s, cur_s);
        }
        if (ch == ')' && remove_right > 0) {
            dfs(index+1, count_left, count_right, remove_left, remove_right-1, s, cur_s);
        }
        
        // 2. remain current char
        cur_s += ch;
        if (ch != '(' && ch != ')') {
            dfs(index+1, count_left, count_right, remove_left, remove_right, s, cur_s);
        } else if (ch == '(') {
            dfs(index+1, count_left+1, count_right, remove_left, remove_right, s, cur_s);
        } else if (ch == ')' && count_right < count_left) {
            dfs(index+1, count_left, count_right+1, remove_left, remove_right, s, cur_s);
        }
    }
};
// @lc code=end

