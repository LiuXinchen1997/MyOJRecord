/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        int cand1 = 0, cand2 = 0, cnt1 = 0, cnt2 = 0;
        for (int num : nums) {
            if (num == cand1) { cnt1 += 1; }
            else if (num == cand2) { cnt2 += 1; }
            else if (cnt1 && cnt2) {
                cnt1 -= 1;
                cnt2 -= 1;
            } else if (!cnt1) {
                cand1 = num;
                cnt1 = 1;
            } else {
                cand2 = num;
                cnt2 = 1;
            }
        }

        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == cand1) { cnt1 += 1; }
            else if (num == cand2) { cnt2 += 1; }
        }
        if (cnt1 > n / 3) { res.push_back(cand1); }
        if (cnt2 > n / 3) { res.push_back(cand2); }
        return res;
    }
};
// @lc code=end

