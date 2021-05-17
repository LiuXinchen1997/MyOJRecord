/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long , vector<long long>, greater<long long>> pq;
        pq.push(1);
        int cnt = 0;
        
        long long pre = 0;
        while (!pq.empty()) {
            long long tmp = pq.top(); pq.pop();
            if (pre == tmp) { continue; }
            cnt += 1;
            pre = tmp;
            if (cnt == n) { return tmp; }
            pq.push(2*tmp);
            pq.push(3*tmp);
            pq.push(5*tmp);
        }

        return 1;
    }
};
// @lc code=end

