/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) { return 0; }
        if (nums.size() == 1) { return 1; }
        
        vector<int> d(nums.size()+1, 0);
        d[1] = nums[0];
        int len = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > d[len]) {
                d[++len] = nums[i];
                continue;
            }

            int l = 1, r = len, pos = 0;
            while (l <= r) {
                int mid = (l+r) / 2;
                if (d[mid] < nums[i]) {
                    l = mid + 1;
                    pos = mid;
                } else {
                    r = mid - 1;
                }
            }
            d[pos + 1] = nums[i];
        }

        return len;
    }
};
// @lc code=end

