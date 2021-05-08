/*
 * @lc app=leetcode.cn id=1723 lang=cpp
 *
 * [1723] 完成所有工作的最短时间
 */

// @lc code=start
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        if (n <= k) {
            int maxn = 0;
            for (auto job : jobs) {
                maxn = max(maxn, job);
            }
        }

        
    }
};
// @lc code=end

