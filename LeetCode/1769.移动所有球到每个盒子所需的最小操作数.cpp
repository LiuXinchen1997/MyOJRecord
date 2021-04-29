/*
 * @lc app=leetcode.cn id=1769 lang=cpp
 *
 * [1769] 移动所有球到每个盒子所需的最小操作数
 */

// @lc code=start
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        for (int i = 0; i < boxes.size(); i++) {
            int sum = 0;
            for (int j = 0; j < boxes.size(); j++) {
                if (i == j) { continue; }
                if (boxes[j] == '1') {
                    sum += abs(j-i);
                }
            }
            ans.push_back(sum);
        }

        return ans;
    }
};
// @lc code=end

