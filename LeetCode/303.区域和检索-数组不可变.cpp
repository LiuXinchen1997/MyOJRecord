/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    vector<int> sum;
    int n;

    // 前缀和
    NumArray(vector<int>& nums) {
        n = nums.size();
        sum = vector<int>(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sum[i+1] = sum[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if (i > j) { swap(i, j); }
        return sum[j+1] - sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

