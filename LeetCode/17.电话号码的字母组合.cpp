/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) { return res; }
        unordered_map<char, string> table{{ {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, 
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} }};

        process(digits, res, table, "", 0);
        return res;
    }

    void process(string& digits, vector<string>& res, unordered_map<char, string>& table, string str, int k) {
        if (str.size() == digits.size()) { 
            res.push_back(str);
            return;
        }

        for (char ch : table[digits[k]]) {
            process(digits, res, table, str + ch, k+1);
        }
    }
};
// @lc code=end

