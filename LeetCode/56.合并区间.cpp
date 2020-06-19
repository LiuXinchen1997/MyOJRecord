/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    static bool my_comp(vector<int>& inter1, vector<int>& inter2) {
        if (inter1[0] < inter2[0]) { return true; }
        else if (inter1[0] == inter2[0]) {
            if (inter1[1] <= inter2[1]) { return true; }
            return false;
        }
        return false;
    }

    int max_of_2(int& a, int& b) {
        if (a < b) { return b; } return a;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > res;
        if (0 == intervals.size()) { return res; }
        if (1 == intervals.size()) { res.push_back(intervals[0]); return res; }

        // sort(intervals.begin(), intervals.end(), my_comp);  // ???
        sort(intervals.begin(), intervals.end());

        vector<int> cur(2, 0);
        cur[0] = intervals[0][0];
        cur[1] = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= cur[1]) {
                cur[1] = max_of_2(cur[1], intervals[i][1]);
            } else {
                res.push_back(cur);
                cur[0] = intervals[i][0];
                cur[1] = intervals[i][1];
            }
        }
        res.push_back(cur);

        return res;
    }
};
// @lc code=end

