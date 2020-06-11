/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (0 == n) { return vector<string>(); }
        vector< vector<string> > vs;
        vector<string> v; v.push_back(""); vs.push_back(v);
        v.clear(); v.push_back("()"); vs.push_back(v);

        for (int i = 2; i <= n; i++) {
            v.clear();
            // cur: i pair
            for (int j = 0; j <= i - 1; j++) {
                for (string str1 : vs[j]) {
                    for (string str2 : vs[i-1-j]) {
                        v.push_back(string(1, '(') + str1 + ')' + str2);
                    }
                }
            }

            vs.push_back(v);
        }

        return vs[n];
    }
};
// @lc code=end

