/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        if (2 == n+1) { return nums[0]; }
        
        int l = 1, r = n, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int cnt = 0;
            for (int num : nums) {
                cnt += (num <= mid);
            }

            if (cnt <= mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
                ans = mid;
            }
        }

        return ans;
    }
};
// @lc code=end

