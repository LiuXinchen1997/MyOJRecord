/*
 * @lc app=leetcode.cn id=1512 lang=cpp
 *
 * [1512] 好数对的数目
 */

// @lc code=start
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int num : nums) {
            if (m.count(num) == 0) { m[num] = 1; }
            else { m[num] += 1; }
        }
        
        int sum = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == 1) { continue; }
            int count = it->second;
            sum += count * (count - 1) / 2;
        }

        return sum; 
    }
};
// @lc code=end

