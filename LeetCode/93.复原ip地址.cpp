/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
class Solution {
public:
    bool check(string str) {
        if (str.size() == 0) { return false; }
        if (str.size() > 3) { return false; }
        if (str.size() == 1) { return true; }
        if (str.size() == 2 && str[0] != '0') { return true; } // 注意：！！！
        if (str.size() == 3) {
            if (str[0] == '1') { return true; }
            else if (str[0] == '2') {
                if (str[1] <= '4') { return true; }
                if (str[1] == '5' && str[2] <= '5') { return true; }
                return false;
            }
        }

        return false;
    }

    void solve(string& str, vector<string>& res, vector<string> cur, int cur_id) {
        if (cur_id >= str.size()) { return; }
        if (cur.size() == 4) {
            string ans = "";
            for (int i = 0; i < 3; i++) { ans += cur[i]; ans += '.'; }
            ans += cur[3];
            res.push_back(ans);
            return;
        }

        for (int i = cur_id; i <= cur_id + 2 && i < str.size(); i++) { // 注意！！！
            string tmp  = str.substr(cur_id, i - cur_id + 1);
            if (!check(tmp)) { continue; }
            cur.push_back(tmp);
            if (cur.size() == 3) {
                if (i >= str.size() - 1) { // 注意！！！
                    cur.pop_back();
                    continue;
                }
                string tmp2 = str.substr(i+1, str.size()-1-i);
                if (check(tmp2)) { cur.push_back(tmp2); }
                else {
                    cur.pop_back();
                    continue;
                }
            }
            solve(str, res, cur, i+1);
            cur.pop_back();
            if (cur.size() == 3) { cur.pop_back(); }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (0 == s.size()) { return res; }

        solve(s, res, vector<string>(), 0);
        return res;
    }
};
// @lc code=end

