/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n, 0);
        vector<int> lens(n, 0);
        vector<int> lefts(n, 0);

        if (nums[0] >= target) { return 1; }
        sums[0] = nums[0];
        for (int i = 1; i < n; i++) {
            if (sums[i-1] < target) {
                sums[i] = sums[i-1] + nums[i];
                lefts[i] = lefts[i-1];
                if (sums[i] >= target) {
                    lens[i] = i - lefts[i-1] + 1;
                    
                    int tmp = 0;
                    for (int j = lefts[i]; j < i; j++) {
                        tmp += nums[j];
                        if (sums[i-1] + nums[i] - tmp >= target) {
                            sums[i] = sums[i-1] + nums[i] - tmp;
                            lefts[i] = j+1;
                            lens[i] = i - lefts[i] + 1;
                        } else {
                            break;
                        }
                    }
                }
            } else {
                int tmp = 0;
                sums[i] = sums[i-1] + nums[i];
                lens[i] = lens[i-1] + 1;
                lefts[i] = lefts[i-1];
                for (int j = lefts[i-1]; j <= i-1; j++) {
                    tmp += nums[j];
                    if (sums[i-1] - tmp + nums[i] >= target) {
                        sums[i] = sums[i-1] - tmp + nums[i];
                        lens[i] = lens[i-1] - (j-lefts[i-1]+1) + 1;
                        lefts[i] = j+1;
                    }
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (0 == res && lens[i] != 0) {
                res = lens[i];
            } else if (0 != res && lens[i] != 0) {
                if (res > lens[i]) { res = lens[i]; }
            }
        }

        return res;
    }
};
// @lc code=end

