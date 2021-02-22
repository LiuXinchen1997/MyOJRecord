/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    static bool myfun(const string& s1, const string& s2)
    {
        return s1 + s2 > s2 + s1;
    }

    string largestNumber(vector<int>& nums) {
        if (nums.size() == 0) { return ""; }
        if (nums.size() == 1) { return to_string(nums[0]); }

        vector<string> str_nums;
        for (int num : nums) {
            str_nums.emplace_back(to_string(num));
        }

        sort(str_nums.begin(), str_nums.end(), myfun);
        if (str_nums[0] == "0") { return "0"; }

        string res = "";
        for (int i = 0; i < str_nums.size(); i++) {
            res += str_nums[i];
        }

        return res;
    }
};
// @lc code=end

