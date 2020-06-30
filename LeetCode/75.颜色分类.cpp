/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void swap(int& a, int& b) { int tmp = a; a = b; b = tmp; }

    void sortColors(vector<int>& nums) {
        int id0 = -1, id1 = -1;
        // id1 for last 0, id2 for last 1
        for (int i = 0; i < nums.size(); i++) {
            if (0 == nums[i]) {
                id0++;
                swap(nums[id0], nums[i]);
                if (id1 < id0) { id1 = id0; }
            }

            if (1 == nums[i]) {
                id1++;
                swap(nums[id1], nums[i]);
            }
        }
    }
};
// @lc code=end

