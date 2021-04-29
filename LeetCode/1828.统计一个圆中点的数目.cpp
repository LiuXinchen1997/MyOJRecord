/*
 * @lc app=leetcode.cn id=1828 lang=cpp
 *
 * [1828] 统计一个圆中点的数目
 */

// @lc code=start
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;

        for (auto query : queries) {
            int sum = 0;
            int x = query[0];
            int y = query[1];
            int r = query[2];
            for (auto point : points) {
                int dx = point[0] - x;
                int dy = point[1] - y;
                sum += (dx*dx + dy*dy <= r*r);
            }
            ans.push_back(sum);
        }

        return ans;
    }
};
// @lc code=end

