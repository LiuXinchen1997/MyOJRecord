/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    // 基于快速排序
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quick_select(nums, 0, nums.size() - 1, k);
    }

    int quick_select(vector<int>& nums, int l, int r, int k) {
        int index = nums.size() - k;
        int q = random_partition(nums, l, r);
        if (q == index) { return nums[q]; }
        
        if (q < index) {
            return quick_select(nums, q+1, r, k);
        } else {
            return quick_select(nums, l, q-1, k);
        }
    }

    int random_partition(vector<int>& nums, int l, int r) {
        int tmp = (rand() % (r - l + 1)) + l;
        swap(nums[tmp], nums[r]);
        
        int x = nums[r];
        int i = l - 1;
        for (int j = l; j < r; j++) {
            /*
            if (nums[j] > x) {
                j++;
            } else {
                swap(nums[++i], nums[j]);
                j++;
            }*/

            if (nums[j] <= x) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[++i], nums[r]);
        return i;
    }
};
// @lc code=end

