/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> s;
        for (int i = 0; i < nums.size(); i++) {
            long long x = nums[i];
            auto it = s.lower_bound(x);
            if (it != s.end() && llabs(*it - x) <= t) {
                return true;
            }

            it = s.upper_bound(x);
            if (it != s.begin() && llabs(*--it - x) <= t) {
                return true;
            }

            s.insert(x);
            if (s.size() > k) {
                s.erase(nums[i-k]);
            }
        }

        return false;
    }
};
// @lc code=end

