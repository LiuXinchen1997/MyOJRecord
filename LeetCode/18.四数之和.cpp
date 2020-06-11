/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> vs;
        if (nums.size() < 4) { return vs; }

        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - 4; i++) {
            for (int j = i+1; j <= nums.size() - 3; j++) {
                int k1 = j + 1;
                int k2 = nums.size() - 1;

                int tmp = nums[i] + nums[j];
                while (k1 < k2) {
                    if (tmp + nums[k1] + nums[k2] == target) {
                        vector<int> v(4, 0);
                        v[0] = nums[i]; v[1] = nums[j]; 
                        v[2] = nums[k1]; v[3] = nums[k2];
                        vs.push_back(v);
                        while (k1 < k2 && nums[k1] == nums[k1+1] && nums[k2] == nums[k2-1]) {
                            k1++; k2--;
                        }
                        k1++; k2--;
                    } else if (tmp + nums[k1] + nums[k2] > target) { k2--; }
                    else { k1++; }
                }

                while (j < nums.size() - 3 && nums[j] == nums[j+1]) { j++; }
            }
            while (i < nums.size() - 4 && nums[i] == nums[i+1]) { i++; }
        }

        return vs;   
    }
};
// @lc code=end

