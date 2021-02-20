/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> res;

    bool is_huiwen(string& str, int l, int r) {
        while (l <= r) {
            if (str[l] != str[r]) { return false; }
            l++;
            r--;
        }

        return true;
    }

    void solve(vector<string> v, string lstr, string rstr) {
        if (is_huiwen(lstr, 0, lstr.size()-1)) {
            v.push_back(lstr);
            if (rstr.size() == 0) { res.push_back(v); return; }

            for (int len = 1; len <= rstr.size(); len++) {
                solve(v, rstr.substr(0, len), rstr.substr(len, string::npos));
            }
        }
    }

    vector<vector<string>> partition(string s) {
        if (s.size() == 0) { return res; }
        
        for (int len = 1; len <= s.size(); len++) {
            solve(vector<string>(), s.substr(0, len), s.substr(len, string::npos));
        }

        return res;
    }
};
// @lc code=end
