/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            if (mp.count(pre - k) == 1) {
                ans += mp[pre-k];
            }
            mp[pre] += 1;
        }

        return ans;
    }
};
// @lc code=end

