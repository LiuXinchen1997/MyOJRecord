/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
class Solution {
public:
    // 超时！！！
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (0 == n || 1 == n) { return 0; }
        
        int res = nums.size();
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i; j <= nums.size(); j++) {
                int min_num = INT_MAX;
                int max_num = INT_MIN;
                for (int id = i; id < j; id++) {
                    min_num = min(min_num, nums[id]);
                    max_num = max(max_num, nums[id]);
                }

                if (i > 0 && nums[i-1] > min_num) { continue; }
                if (j < nums.size() && nums[j] < max_num) { continue; }
                
                bool order = true;
                for (int id = 0; id < i; id++) {
                    if (nums[id] > nums[id+1]) { order = false; break; }
                }
                if (!order) { continue; }
                for (int id = j; id < nums.size() - 1; id++) {
                    if (nums[id] > nums[id+1]) { order = false; break; }
                }
                if (!order) { continue; }

                res = min(res, j-i);
            }
        }
        return res;
    }
};
// @lc code=end

