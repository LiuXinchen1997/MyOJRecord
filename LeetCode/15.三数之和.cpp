/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vs;
        if (nums.size() < 3) { return vs; }

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) { break; }
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                if (nums[i] + nums[j] + nums[k] < 0) { j++; }
                else if (nums[i] + nums[j] + nums[k] > 0) { k--; }
                else {
                    vector<int> v(3,0);
                    v[0] = nums[i]; v[1] = nums[j]; v[2] = nums[k];
                    vs.push_back(v);

                    while (j < k && nums[j] == nums[j+1]) { j++; }
                    j++; k--;
                }
            }

            while (i < nums.size() - 2 && nums[i] == nums[i+1]) { i++; }
        }

        return vs;
    }
};
// @lc code=end

