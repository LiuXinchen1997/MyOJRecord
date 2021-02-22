/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    int gcd(int a, int b)
    {
        if (a < b) {
            int tmp = b; b = a; a = tmp;
        }

        while (true) {
            if (a % b == 0) { return b; }
            int tmp = (a % b);
            a = b; b = tmp;
        }
    }

    void rotate(vector<int>& nums, int k) {
        if (nums.size() <= 1 || k == 0) { return; }

        int n = nums.size();
        int L = gcd(n, k);

        for (int i = 0; i < L; i++) {
            int temp = nums[i];
            int cur_pos = i;
            do {
                swap(nums[(cur_pos + k) % n], temp);
                cur_pos = ((cur_pos + k) % n);
            } while (cur_pos != i);
        }
    }
};
// @lc code=end

