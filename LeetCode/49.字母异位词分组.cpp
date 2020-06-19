/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        if (0 == strs.size()) { return res; }
        if (1 == strs.size()) { res.push_back(strs); return res; }

        map<vector<int>, vector<string> > m;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> count(26, 0);
            for (int j = 0; j < strs[i].size(); j++) {
                count[strs[i][j] - 'a'] += 1;
            }
            if (m.count(count) == 0) {
                m[count] = vector<string>();
            }
            m[count].push_back(strs[i]);
        }

        for (map<vector<int>, vector<string> >::iterator it = m.begin(); it != m.end(); it++) {
            res.push_back(it->second);
        }

        return res;
    }
};
// @lc code=end

