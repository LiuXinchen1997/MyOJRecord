/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26, 0);
        vector<bool> vis(26, false);
        for (char ch : s) {
            cnt[ch - 'a'] += 1;
        }

        string stk;
        for (char ch : s) {
            if (vis[ch - 'a'] == false) {
                while (!stk.empty() && stk.back() > ch) {
                    if (cnt[stk.back() - 'a'] > 0) {
                        vis[stk.back() - 'a'] = false;
                        stk.pop_back(); 
                    } else {
                        break;
                    }
                }
                stk.push_back(ch);
                vis[ch - 'a'] = true;
            }
            cnt[ch - 'a'] -= 1;
        }

        return stk;
    }
};
// @lc code=end

