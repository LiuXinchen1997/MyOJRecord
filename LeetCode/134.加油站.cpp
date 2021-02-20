/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if (0 == n) { return -1; }

        for (int start = 0; start < n; start++) {
            int cur_pos = start;
            int cur_cap = 0;
            while (true) {
                cur_cap = cur_cap + gas[cur_pos] - cost[cur_pos];
                if (cur_cap < 0) { break; }

                cur_pos++;
                if (cur_pos == n) { cur_pos = 0; }
                if (cur_pos == start) { return start; }
            }
        }

        return -1;
    }
};
// @lc code=end

