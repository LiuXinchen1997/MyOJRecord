/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 0) { return 0; }
        if (ratings.size() == 1) { return 1; }
        
        vector<int> left(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) { left[i] = left[i-1] + 1; }
            else { left[i] = 1; }
        }

        int right = 1;
        int res = max(right, left[ratings.size()-1]);
        for (int i = ratings.size()-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                right = right + 1;
            } else {
                right = 1;
            }
            res += max(right, left[i]);
        }

        return res;
    }
};
// @lc code=end

