/*
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 */

// @lc code=start
class Solution {
public:
    static constexpr int TARGET = 24;
    static constexpr double EPSILON = 1e-6;
    static constexpr int ADD = 1, SUBSTRACT = 2, MULTIPLY = 3, DEVIDE = 4;

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int card : cards) {
            nums.emplace_back(static_cast<double>(card));
        }
        return solve(nums);
    }

    bool solve(vector<double>& nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - TARGET) < EPSILON;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) { continue; }
                
                vector<double> nums2;
                for (int k = 0; k < nums.size(); k++) {
                    if (k == i || k == j) { continue; }
                    nums2.push_back(nums[k]);
                }

                for (int k = 1; k <= 4; k++) {
                    if (k == ADD) {
                        nums2.push_back(nums[i] + nums[j]);
                    } else if (k == SUBSTRACT) {
                        nums2.push_back(nums[i] - nums[j]);
                    } else if (k == MULTIPLY) {
                        nums2.push_back(nums[i] * nums[j]);
                    } else if (k == DEVIDE) {
                        if (fabs(nums[j]) < EPSILON) { continue; }
                        nums2.push_back(nums[i] / nums[j]);
                    }

                    if (solve(nums2)) { return true; }
                    nums2.pop_back();
                }
            }
        }

        return false;
    }
};
// @lc code=end

