/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.size() == 0) { return 0; }
        unordered_map<char, int> freq;
        for (auto ch : tasks) {
            freq[ch] += 1;
        }
        
        vector<int> next_valids;
        vector<int> rests;
        for (auto [_, v] : freq) {
            next_valids.push_back(1);
            rests.push_back(v);
        }

        int time = 0;
        for (auto task : tasks) {
            time += 1;
            int min_next_vals = INT_MAX;
            for (int i = 0; i < rests.size(); i += 1) {
                if (rests[i] > 0) {
                    min_next_vals = min(min_next_vals, next_valids[i]);
                }
            }
            time = max(time, min_next_vals);
            
            int id = -1;
            for (int i = 0; i < rests.size(); i += 1) {
                if (rests[i] && time >= next_valids[i]) {
                    if (id == -1 || rests[i] > rests[id]) {
                        id = i;
                    }
                }
            }
            rests[id] -= 1;
            next_valids[id] = time + n + 1;
        }

        return time;
    }
};
// @lc code=end

