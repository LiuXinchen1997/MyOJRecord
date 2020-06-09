/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int min_of_2(int a, int b) {
        if (a < b) { return a; }
        return b;
    }

    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int res = min_of_2(height[i], height[j]) * (j - i);
        while (i < j) {
            if (height[i] < height[j]) { i++; }
            else { j--; }

            int new_area = min_of_2(height[i], height[j]) * (j - i);
            if (res < new_area) { res = new_area; }
        }

        return res;
    }
};
// @lc code=end

