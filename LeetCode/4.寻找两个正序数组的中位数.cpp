/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    int find_kth_number(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int index1 = 0;
        int index2 = 0;

        while (1) {
            if (index1 == n1) {
                return nums2[index2 + k - 1];
            }
            if (index2 == n2) {
                return nums1[index1 + k - 1];
            }
            if (1 == k) {
                return min(nums1[index1], nums2[index2]);
            }

            int new_index1 = min(index1 + k/2 - 1, n1 - 1);
            int new_index2 = min(index2 + k/2 - 1, n2 - 1);
            if (nums1[new_index1] <= nums2[new_index2]) {
                k -= new_index1 + 1 - index1;
                index1 = new_index1 + 1;
            } else {
                k -= new_index2 + 1 - index2;
                index2 = new_index2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if ((n1 + n2) % 2 == 1) {
            return find_kth_number(nums1, nums2, (n1+n2)/2+1);
        } else {
            return (find_kth_number(nums1, nums2, (n1+n2)/2) + find_kth_number(nums1, nums2, (n1+n2)/2+1)) / 2.0;
        }
    }
};
// @lc code=end

