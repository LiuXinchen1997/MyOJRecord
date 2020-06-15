/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(nums[i])) {
                vector<int> v(2, 0);
                v[0] = m[nums[i]];
                v[1] = i;
                return v;
            } else {
                m[target - nums[i]] = i;
            }
        }

        return vector<int>();
    }
};
// @lc code=end

