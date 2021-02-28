/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    struct Status {
        int lsum, rsum, msum, isum;
        Status() {};
        Status(int a, int b, int c, int d) : lsum(a), rsum(b), msum(c), isum(d) {};
    };

    Status max_array(vector<int>& nums, int l, int r) {
        if (l == r) {
            return Status(nums[l], nums[l], nums[l], nums[l]);
        }

        int m = (l + r) / 2;
        // [l, m] [m+1, r]
        Status ls = max_array(nums, l, m);
        Status rs = max_array(nums, m+1, r);
        Status s;
        s.isum = ls.isum + rs.isum;
        s.lsum = max(ls.isum + rs.lsum, ls.lsum);
        s.rsum = max(rs.isum + ls.rsum, rs.rsum);
        s.msum = max(ls.msum, rs.msum);
        s.msum = max(s.msum, ls.rsum + rs.lsum);

        return s;
    }

    int maxSubArray(vector<int>& nums) {
        Status s = max_array(nums, 0, nums.size()-1);
        return s.msum;
    }
};
// @lc code=end

