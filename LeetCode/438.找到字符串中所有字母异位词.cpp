/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    unordered_map<char, int> p_m;
    unordered_map<char, int> s_m;

    bool is_pair() {
        for (auto it : p_m) {
            if (it.second != s_m[it.first]) { return false; }
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() == 0) {
            return ans;
        }
        
        for (char ch : p) {
            p_m[ch] += 1;
        }

        for (int i = 0; i < p.size(); i++) {
            s_m[s[i]] += 1;
        }
        
        if (is_pair()) {
            ans.push_back(0);
        }
        for (int i = 1; i + p.size() - 1 < s.size(); i++) {
            s_m[s[i-1]] -= 1;
            s_m[s[i+p.size()-1]] += 1;

            if (is_pair()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
// @lc code=end

