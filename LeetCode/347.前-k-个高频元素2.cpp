/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.size() == 0) { return res; }

        unordered_map<int, int> m;
        for (auto& num : nums) {
            m[num] += 1;
        }

        vector<pair<int, int>> pairs;
        for (auto& ele : m) {
            pairs.emplace_back(make_pair(ele.first, ele.second));
        }

        sort(pairs.begin(), pairs.end(), [](const auto& e1, const auto& e2) {
            return e1.second >= e2.second;
        });

        for (int i = 0; i < k; i++) {
            res.push_back(pairs[i].first);
        }

        return res;
    }
};
// @lc code=end

