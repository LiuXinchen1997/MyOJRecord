/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) {
            intervals.emplace_back(newInterval);
            return intervals;
        }
        
        int new_start = newInterval[0];
        int new_end = newInterval[1];
        int start_id = 0;
        for (; start_id < intervals.size(); start_id++) {
            int cur_start = intervals[start_id][0];
            int cur_end = intervals[start_id][1];
            if (new_start <= cur_end) { break; }
        }
        
        if (start_id == intervals.size()) {
            vector<int> tmp = {new_start, new_end};
            intervals.emplace_back(tmp);
            return intervals;
        }

        if (new_end < intervals[start_id][0]) {
            vector<int> tmp = {new_start, new_end};
            intervals.insert(intervals.begin()+start_id, tmp);
            return intervals;
        }

        new_start = min(new_start, intervals[start_id][0]);
        int delete_start = start_id;
        int delete_end = start_id+1;
        while (1) {
            if (delete_end == intervals.size()) { break; }
            if (new_end < intervals[delete_end][0]) { break; }
            delete_end += 1;
        }
        new_end = max(new_end, intervals[delete_end-1][1]);
        intervals.erase(intervals.begin()+delete_start, intervals.begin()+delete_end);
        vector<int> tmp = {new_start, new_end};
        intervals.insert(intervals.begin()+start_id, tmp);
        return intervals;
    }
};
// @lc code=end

