/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (int num : nums) {
            if (s.count(num) == 0) {
                s.insert(num);
            } else {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

