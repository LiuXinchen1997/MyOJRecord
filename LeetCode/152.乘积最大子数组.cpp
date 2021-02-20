/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int max_of_2(int a, int b) {
        return a > b ? a : b;
    }

    int max_of_3(int a, int b, int c) {
        return max_of_2(max_of_2(a, b), c);
    }

    int min_of_2(int a, int b) {
        return a < b ? a : b;
    }

    int min_of_3(int a, int b, int c) {
        return min_of_2(min_of_2(a, b), c);
    }

    int maxProduct(vector<int>& nums) {
        vector<int> max_ps(nums.size(), 0);
        vector<int> min_ps(nums.size(), 0);

        max_ps[0] = nums[0];
        min_ps[0] = nums[0];
        int res = max_ps[0];
        for (int i = 1; i < nums.size(); i++) {
            max_ps[i] = max_of_3(max_ps[i-1]*nums[i], min_ps[i-1]*nums[i], nums[i]);
            min_ps[i] = min_of_3(max_ps[i-1]*nums[i], min_ps[i-1]*nums[i], nums[i]);

            if (res < max_ps[i]) {
                res = max_ps[i];
            }
        }

        return res;
    }
};
// @lc code=end

