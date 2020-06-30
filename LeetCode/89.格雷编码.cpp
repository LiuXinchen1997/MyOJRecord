/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        for (int i = 1; i <= n; i++) {
            vector<int> tmp;
            for (int j = 0; j < res.size(); j++) {
                tmp.push_back(res[j]);
            }
            for (int j = res.size() - 1; j >= 0; j--) {
                tmp.push_back(res[j] + (1 << (i-1)));
            }
            res = tmp;
        }

        return res;
    }
};
// @lc code=end

