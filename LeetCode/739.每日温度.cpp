/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        if (1 == n) { return vector<int>(1, 0); }
        
        vector<int> res(n, 0);
        stack<int> stk;
        for (int i = 0; i < T.size(); i++) {
            if (stk.empty() || T[i] <= T[stk.top()]) {
                stk.push(i);
                continue;
            }

            while (!stk.empty() && T[i] > T[stk.top()]) {
                int ind = stk.top(); stk.pop();
                res[ind] = i - ind;
            }
            stk.push(i);
        }

        return res;
    }
};
// @lc code=end

