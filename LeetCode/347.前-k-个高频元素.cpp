/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    static bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
       return p1.second > p2.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto& num : nums) {
            m[num] += 1;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&comp)> q(comp);
        for (auto& [num, count] : m) {
            if (q.size() < k) {
                q.emplace(make_pair(num, count));
            } else if (q.size() == k) {
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(make_pair(num, count));
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.top().first);
            q.pop();
        }

        return ans;
    }
};
// @lc code=end

