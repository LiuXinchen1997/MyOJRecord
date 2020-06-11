/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start

// BFS
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if (0 == digits.size()) { return v; }

        string alps[8] = { "abc", "def", "ghi", "jkl", "mno", 
        "pqrs", "tuv", "wxyz" };

        queue<string> qs;
        string tmp = alps[digits[0] - '2'];
        for (int i = 0; i < tmp.size(); i++) {
            qs.push(string(1, tmp[i]));
        }
        while (!qs.empty()) {
            tmp = qs.front();
            qs.pop();

            if (tmp.size() >= digits.size()) {
                v.push_back(tmp);
                continue;
            }

            string str = alps[digits[tmp.size()] - '2'];
            for (int i = 0; i < str.size(); i++) {
                qs.push(tmp + str[i]);
            }
        }

        return v;
    }
};
// @lc code=end

