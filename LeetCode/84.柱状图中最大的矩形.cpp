/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int max_of_2(int a, int b) {
        return a < b ? b : a;
    }

    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) { return 0; }
        if (heights.size() == 1) { return heights[0]; }

        stack<int> stk;
        int maxn = 0;
        for (int i = 0; i < heights.size(); i++) {
            int height = heights[i];
            while (!stk.empty() && height < heights[stk.top()]) {
                int right_id = stk.top(); stk.pop();
                if (stk.empty()) {
                    maxn = max_of_2(i * heights[right_id], maxn);
                } else {
                    maxn = max_of_2((i - stk.top() - 1) * heights[right_id], maxn);
                }
            }
            stk.push(i);
        }
        
        while (!stk.empty()) {
            int right_id = stk.top(); stk.pop();
            if (stk.empty()) {
                maxn = max_of_2(heights.size() * heights[right_id], maxn);
            } else {
                maxn = max_of_2((heights.size() - stk.top() - 1) * heights[right_id], maxn);
            }
        }

        return maxn;
    }
};
// @lc code=end

