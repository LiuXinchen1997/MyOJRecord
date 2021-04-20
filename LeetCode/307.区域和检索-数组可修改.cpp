/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
class NumArray {
public:
    vector<int> tree;
    int len;

    NumArray(vector<int>& nums) {
        len = nums.size();
        tree = vector<int>(2*len, 0);

        for (int i = len, j = 0; i < 2*len; i++, j++) {
            tree[i] = nums[j];
        }
        for (int i = len-1; i > 0; i--) {
            tree[i] = tree[2*i] + tree[2*i+1];
        }
    }
    
    void update(int index, int val) {
        int pos = index + len;
        tree[pos] = val;
        pos /= 2;
        while (pos > 0) {
            tree[pos] = tree[2*pos] + tree[2*pos+1];
            pos /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        left = len + left;
        right = len + right;
        int sum = 0;

        // left: [left, left]
        // left/2
        while (left <= right) {
            if (left % 2 == 1) {
                sum += tree[left];
                left += 1;
            }
            if (right % 2 == 0) {
                sum += tree[right];
                right -= 1;
            }
            left /= 2;
            right /= 2;
        }

        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

