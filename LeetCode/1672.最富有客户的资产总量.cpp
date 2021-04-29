/*
 * @lc app=leetcode.cn id=1672 lang=cpp
 *
 * [1672] 最富有客户的资产总量
 */

// @lc code=start
class Solution {
public:
    int sum(vector<int>& account) {
        int sum = 0;
        for (int num : account) { sum += num; }
        return sum;
    }
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxn = 0;
        for (auto account : accounts) {
            maxn = max(maxn, sum(account));
        }

        return maxn;
    }
};
// @lc code=end

