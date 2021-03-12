/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;
        int cur_i = 0;
        int n = preorder.size();

        while (true) {
            int tmp_i = cur_i;
            while (tmp_i < n && preorder[tmp_i] != ',') {
                tmp_i += 1;
            }

            string cur = preorder.substr(cur_i, tmp_i - cur_i);
            if (slots == 0) { return false; }
            slots -= 1;
            if (cur != "#") {
                slots += 2;
            }

            cur_i = tmp_i + 1;
            if (cur_i >= n) {
                break;
            }
        }

        if (slots == 0) { return true; }
        return false;
    }
};
// @lc code=end

