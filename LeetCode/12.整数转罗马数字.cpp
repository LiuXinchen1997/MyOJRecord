/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        int a[4] = {0};
        a[0] = num / 1000;
        num = (num % 1000);
        a[1] = num / 100;
        num = (num % 100);
        a[2] = num / 10;
        a[3] = (num % 10);

        int counts[13] = {0};
        string roman[13] = { "M", "CM", "D", "CD", "C", "XC", 
        "L", "XL", "X", "IX", "V", "IV", "I" };
        counts[0] = a[0];

        if (0 != a[1]) {
            if (9 == a[1]) { counts[1]++; }
            else if (a[1] >= 5 && a[1] <= 8) { 
                counts[2]++;
                counts[4] += (a[1] - 5);
            } else if (4 == a[1]) { counts[3]++; }
            else if (a[1] >= 1 && a[1] <= 3) { counts[4] += a[1]; }
        }

        if (0 != a[2]) {
            if (9 == a[2]) { counts[5]++; }
            else if (a[2] >= 5 && a[2] <= 8) { 
                counts[6]++;
                counts[8] += (a[2] - 5);
            } else if (4 == a[2]) { counts[7]++; }
            else if (a[2] >= 1 && a[2] <= 3) { counts[8] += a[2]; }
        }

        if (0 != a[3]) {
            if (9 == a[3]) { counts[9]++; }
            else if (a[3] >= 5 && a[3] <= 8) { 
                counts[10]++;
                counts[12] += (a[3] - 5);
            } else if (4 == a[3]) { counts[11]++; }
            else if (a[3] >= 1 && a[3] <= 3) { counts[12] += a[3]; }
        }

        string res = "";
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < counts[i]; j++) {
                res += roman[i];
            }
        }

        return res;
    }
};
// @lc code=end

