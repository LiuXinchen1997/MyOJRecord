/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 */

// @lc code=start
class Solution {
public:
    long getCount(long prefix, long n) {
        long cur = prefix;
        long next = prefix + 1;
        long count = 0;
        while (cur <= n) {
            count += min(next, n+1) - cur;
            cur *= 10;
            next *= 10;
        }

        return count;
    }

    int findKthNumber(int n, int k) {
        long p = 1;
        long prefix = 1;
        while (p < k) {
            long count = getCount(prefix, n);
            if (p + count > k) {
                prefix *= 10;
                p++;
            } else {
                prefix += 1;
                p += count;
            }
        }

        return static_cast<int>(prefix);
    }
};
// @lc code=end

