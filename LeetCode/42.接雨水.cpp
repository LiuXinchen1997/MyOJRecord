/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    // 双指针
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max) { left_max = height[left]; }
                else { ans += (left_max - height[left]); }
                left += 1;
            } else {
                if (height[right] >= right_max) { right_max = height[right]; }
                else { ans += (right_max - height[right]); }
                right -= 1;
            }
        }

        return ans;
    }
};
// @lc code=end

