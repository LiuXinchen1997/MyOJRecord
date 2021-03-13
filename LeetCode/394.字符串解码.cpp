/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<int> stk;
        
        int id = 0;
        while (true) {
            if (id >= s.size()) { break; }
            if (s[id] != '[' && s[id] != ']') { id++; continue; }

            if (s[id] == '[') {
                stk.push(id);
                id++;
                continue;
            }

            // s[id] == ']'
            int l_id = stk.top(); stk.pop();
            int tmp_id = l_id - 1;
            int num = 0;
            while (tmp_id >= 0 && s[tmp_id] >= '0' && s[tmp_id] <= '9') {
                tmp_id -= 1;
            }
            int ll_id = tmp_id + 1;
            tmp_id += 1;
            for (; tmp_id < l_id; tmp_id++) {
                num *= 10;
                num += (s[tmp_id] - '0');
            }
            string tmp_s = "";
            for (int i = 0; i < num; i++) {
                tmp_s += s.substr(l_id+1, id-l_id-1);
            }
            s.replace(ll_id, id-ll_id+1, tmp_s);
            id = ll_id + tmp_s.size();
        }

        return s;
    }
};
// @lc code=end

