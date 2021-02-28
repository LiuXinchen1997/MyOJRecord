/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */

// @lc code=start
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() == 1) { return true; }
        
        int flag = 0;
        for (int i = 0; i < A.size() - 1; i++) {
            if (A[i] == A[i+1]) { continue; }
            if (A[i] > A[i+1]) {
                if (0 == flag) {
                    flag = -1;
                } else if (1 == flag) { return false; }
                else if (-1 == flag) { continue; }
            }
            if (A[i] < A[i+1]) {
                if (0 == flag) {
                    flag = 1;
                } else if (-1 == flag) { return false; }
                else if (1 == flag) { continue; }
            }
        }

        return true;
    }
};
// @lc code=end

