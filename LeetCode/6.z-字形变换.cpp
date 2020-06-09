// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem6.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (1 == numRows || "" == s) { return s; }
        int len = s.size();
        char* chs = new char[len+2]; chs[len] = '\0';
        int i = 0;
        for (int row = 1; row <= numRows; row++) {
            int cur = row - 1;
            if (1 == row || numRows == row) {
                while (cur < len && i < len) {
                    chs[i] = s[cur];
                    cur += 2 * numRows - 2;
                    i++;
                }
            } else {
                bool flag = true;
                while (cur < len && i < len) {
                    chs[i] = s[cur];
                    if (flag) { cur += 2 * numRows - 2 * row; flag = false; } 
                    else { cur += 2 * row - 2; flag = true; }
                    i++;
                }
            }
        }

        return string(chs, len);
    }
};
// @lc code=end

