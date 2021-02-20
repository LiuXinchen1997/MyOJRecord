/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for (auto word : wordDict) {
            words.insert(word);
        }

        vector<bool> dp(s.size() + 1);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            dp[i] = false;
            for (int j = 0; j < i; j++) {
                if (dp[j] && words.find(s.substr(j, i-j)) != words.end()) { 
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};
// @lc code=end
