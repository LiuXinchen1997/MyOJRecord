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
        
        int inc = 1;
        int dec = 0;
        int pre = 1;
        int res = 1;
        
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] >= ratings[i-1]) {
                pre = (ratings[i] == ratings[i-1]) ? 1 : pre + 1;
                res += pre;
                inc = pre;
                dec = 0;
            } else {
                pre = 1;
                dec += 1;
                if (dec == inc) { dec += 1; }
                res += dec;
            }
        }

        return res;
    }
};
// @lc code=end

