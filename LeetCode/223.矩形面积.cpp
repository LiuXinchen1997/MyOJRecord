/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (A > E) {
            swap(A, E);
            swap(B, F);
            swap(C, G);
            swap(D, H);
        }
        
        long long a1 = C - A;
        long long b1 = D - B;
        long long a2 = G - E;
        long long b2 = H - F;
        long long res = a1*b1 + a2*b2;

        if (F >= D || H <= B || E >= C) { return res; }
        
        return res - (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
    }
};
// @lc code=end

