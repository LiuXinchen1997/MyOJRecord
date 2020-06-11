/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
// bfs
struct Ele {
    string str;
    int l, r;
    Ele(string str_, int l_, int r_) : str(str_), l(l_), r(r_) {}
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vs;
        if (0 == n) { return vs; }
        else if (1 == n) { vs.push_back("()"); return vs; }

        queue<Ele> q;
        q.push(Ele("(", n-1, n));
        while (!q.empty()) {
            Ele ele = q.front(); q.pop();
            if (ele.l == 0 && ele.r == 0) { vs.push_back(ele.str); continue; }

            if (ele.l > 0) {
                q.push(Ele(ele.str+'(', ele.l-1, ele.r));
            }
            if (ele.r > ele.l) {
                q.push(Ele(ele.str+')', ele.l, ele.r-1));
            }
        }

        return vs;

    }
};
// @lc code=end

