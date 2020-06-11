/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() == 3) { return nums[0]+nums[1]+nums[2]; }
        sort(nums.begin(), nums.end());

        int max_dist = INT_MAX;
        int sum3;
        for (int i = 0; i < nums.size()-2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int tmp = nums[i] + nums[j] + nums[k];
                if (tmp == target) { return target; }
                else if (tmp < target) {
                    if (target - tmp < max_dist) { sum3 = tmp; max_dist = target - tmp; }
                    j++;
                } else {
                    if (tmp - target < max_dist) { sum3 = tmp; max_dist = tmp - target; }
                    k--;
                }
            }
        }

        return sum3;
    }
};
// @lc code=end

