/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    stack<int> stk;
    stack<int> min_stk;

    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int val) {
        stk.push(val);
        if (min_stk.empty()) {
            min_stk.push(val);
        } else {
            if (min_stk.top() >= val) {
                min_stk.push(val);
            }
        }
    }
    
    void pop() {
        int cur = stk.top(); stk.pop();
        if (cur == min_stk.top()) {
            min_stk.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        if (min_stk.empty()) {
            return INT_MIN;
        }
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

