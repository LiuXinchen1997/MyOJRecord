/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        for (int num : nums1) { s1.insert(num); }
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        if (s1.count(nums2[0])) { res.push_back(nums2[0]); }
        for (int i = 1; i < nums2.size(); i++) {
            while (i < nums2.size() && nums2[i] == nums2[i-1]) { i++; }
            if (i >= nums2.size()) { break; }

            if (s1.count(nums2[i])) { res.push_back(nums2[i]); }
        }

        return res;
    }
};
// @lc code=end

