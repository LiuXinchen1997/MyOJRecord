/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

// @lc code=start
class Solution {
public:
    int get_id(char ch) {
        if ('a' <= ch && ch <= 'z') { return ch - 'a'; }
        return ch - 'A' + 26;
    }

    int numJewelsInStones(string jewels, string stones) {
        vector<int> chs(52, 0);
        for (char ch : jewels) {
            chs[get_id(ch)] = 1;
        }

        int sum = 0;
        for (char ch : stones) {
            sum += chs[get_id(ch)];
        }
        return sum;
    }
};
// @lc code=end

