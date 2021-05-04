/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */

// @lc code=start
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if (answers.size() == 0) { return 0; }

        unordered_map<int, int> um;
        for (int answer : answers) {
            um[answer] += 1;
        }

        int res = 0;
        for (auto it = um.begin(); it != um.end(); it++) {
            int key = it->first;
            int val = it->second;

            if (val % (key + 1) == 0) {
                res += val;
            } else {
                res += (val / (key + 1) + 1) * (key + 1);
            }
        }

        return res;
    }
};
// @lc code=end

