/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 */

// @lc code=start
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int height = wall.size();
        if (0 == height) { return 0; }

        unordered_map<int, int> cnt;
        for (auto row : wall) {
            for (int i = 0; i < row.size() - 1; i++) {
                cnt[row[i]] += 1;
                row[i+1] += row[i];
            }
        }

        int maxn = 0;
        for (auto it : cnt) {
            maxn = max(maxn, it.second);
        }

        return height - maxn;
    }
};
// @lc code=end

