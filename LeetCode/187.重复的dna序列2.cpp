/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() <= 10) { return res; }

        map<string, int> m;
        for (int i = 0; i + 9 < s.size(); i++) {
            string str = s.substr(i, 10);
            if (m.count(str) == 0) { 
                m[str] = 1;
                continue; 
            }

            m[str] += 1;
            if (m[str] == 2) { res.emplace_back(str); }
        }

        return res;
    }
};
// @lc code=end

