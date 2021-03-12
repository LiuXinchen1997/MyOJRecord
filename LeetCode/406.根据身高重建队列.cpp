/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& u1, const vector<int>& u2) {
            return (u1[0] < u2[0] || (u1[0] == u2[0] && u1[1] > u2[1]));
        });
        
        vector<vector<int>> queue(people.size(), vector<int>(2, -1));
        for (auto& p : people) {
            int i = 0;
            for (auto& q : queue) {
                if (q[0] == -1) { i++; }
                if (i == p[1] + 1) {
                    q[0] = p[0];
                    q[1] = p[1];
                    break;
                }
            }
        }

        return queue;
    }
};
// @lc code=end

