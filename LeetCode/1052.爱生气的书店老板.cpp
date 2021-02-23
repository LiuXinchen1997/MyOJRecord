/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */

// @lc code=start
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        if (customers.size() == 0) {
            return 0;
        }
        
        int n = grumpy.size();
        int cur_res = 0;
        for (int i = 0; i < n; i++) {
            if (0 == grumpy[i]) {
                cur_res += customers[i];
            }
        }

        if (0 == X) { return cur_res; }
        
        int tmp = 0;
        int max_res = -1;
        for (int i = 0; i + X - 1 < n; i++) {
            if (0 == i) {
                for (int j = i; j < i + X; j++) {
                    if (grumpy[j] == 1) { tmp += customers[j]; }
                }
            } else {
                if (grumpy[i-1] == 1) { tmp -= customers[i-1]; }
                if (grumpy[i+X-1] == 1) { tmp += customers[i+X-1]; }
            }

            if (cur_res + tmp > max_res) {
                max_res = cur_res + tmp;
            }
        }

        return max_res;
    }
};
// @lc code=end

