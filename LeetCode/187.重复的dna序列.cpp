/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() <= 10) { return res; }

        map<char, int> char2int;
        char2int['A'] = 0;
        char2int['C'] = 1;
        char2int['G'] = 2;
        char2int['T'] = 3;
        int* s_num = new int[s.size()];
        for (int i = 0; i < s.size(); i++) {
            s_num[i] = char2int[s[i]];
        }

        map<int, int> m;
        int L = 10;
        int cur = 0;
        for (int i = 0; i + 9 < s.size(); i++) {
            if (0 == i) {
                for (int j = 0; j < L; j++) {
                    cur <<= 2;
                    cur |= s_num[i+j];
                }
            } else {
                // -i-1, +i+9
                cur <<= 2;
                cur |= s_num[i+9];
                cur &= ~(3 << 2*L);
            }

            if (m.count(cur) == 0) {
                m[cur] = 1;
            } else if (m[cur] == 1) {
                m[cur] += 1;
                res.emplace_back(s.substr(i, L));
            } else {
                m[cur] += 1;
            }
        }

        delete []s_num;
        return res;
    }
};
// @lc code=end

