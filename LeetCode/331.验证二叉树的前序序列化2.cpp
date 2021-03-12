/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        int cur_i = 0;
        stack<int> stk;
        stk.push(1);
        while (true) {
            int tmp_i = cur_i;
            while (tmp_i < n && preorder[tmp_i] != ',') {
                tmp_i += 1;
            }
            
            string str = preorder.substr(cur_i, tmp_i - cur_i);
            if (stk.empty()) { return false; }
            int tmp = stk.top();
            stk.pop();
            tmp -= 1;
            if (tmp > 0) {
                stk.push(tmp);
            }

            if (str != "#") {
                stk.push(2);
            }
            
            cur_i = tmp_i + 1;
            if (cur_i >= n) {
                break;
            }
        }

        if (stk.empty()) {
            return true;
        }
        return false;
    }
};
// @lc code=end

