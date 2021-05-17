/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
struct Obj {
    int val, id;
    Obj() {};
    Obj(int _val, int _id) : val(_val), id(_id) {};

    bool operator< (const Obj& o) const {
        if (val < o.val) { return true; }
        return false;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<Obj> pq;
        for (int i = 0; i < k; i++) {
            pq.push(Obj(nums[i], i));
        }

        vector<int> res;
        res.push_back(pq.top().val);
        for (int i = k; i < nums.size(); i++) {
            pq.push(Obj(nums[i], i));
            while (pq.top().id <= i - k) { pq.pop(); }
            res.push_back(pq.top().val);
        }
        
        return res;
    }
};
// @lc code=end

