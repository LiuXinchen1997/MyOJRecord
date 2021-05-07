/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        for (int num : nums) {
            us.insert(num);
        }
        
        int maxn = 0;
        for (int num : nums) {
            if (us.count(num-1)) {
                continue;
            }

            int cur_len = 0;
            int cur_num = num;
            while (us.count(cur_num)) {
                cur_len += 1;
                cur_num += 1;
            }
            maxn = max(maxn, cur_len);
        }

        return maxn;
    }
};
// @lc code=end

