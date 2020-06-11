/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
// dfs
class Solution {
public:
    void func(string str, int l, int r, vector<string>& vs)
    {
        if (0 == l && 0 == r) { vs.push_back(str); return; }

        if (l > 0) { func(str+'(', l-1, r, vs); }
        if (r > l) { func(str+')', l, r-1, vs); }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> vs;
        if (0 == n) { return vs; }
        else if (1 == n) { vs.push_back("()"); return vs; }

        func("", n, n, vs);

        return vs;
    }
};
// @lc code=end

