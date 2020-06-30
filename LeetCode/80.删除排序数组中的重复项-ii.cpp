/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    void swap(int& a, int& b) {
        int tmp = a; a = b; b = tmp;
    }

    int removeDuplicates(vector<int>& nums) {
        if (0 == nums.size()) { return 0; }

        int status = 1;
        int real_i = 0;
        int cur = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == cur) {
                if (1 == status) { 
                    status = 2;
                    swap(nums[real_i+1], nums[i]); 
                    real_i++; 
                } else if (2 == status) { continue; }
            } else {
                cur = nums[i];
                status = 1;
                swap(nums[real_i+1], nums[i]);
                real_i++;
            }
        }

        return real_i+1;
    }
};
// @lc code=end

