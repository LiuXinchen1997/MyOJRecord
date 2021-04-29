/*
 * @lc app=leetcode.cn id=1822 lang=cpp
 *
 * [1822] 数组元素积的符号
 */

// @lc code=start
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int fu_count = 0;
        for (int num : nums) {
            if (num == 0) { return 0; }
            if (num < 0) { fu_count += 1; }
        }

        if (fu_count % 2 == 0) { return 1; }
        else { return -1; }
    }
};
// @lc code=end

