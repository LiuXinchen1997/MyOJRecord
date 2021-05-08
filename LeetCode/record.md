### 1 基础知识巩固

#### 1.1 算法
1. 并查集
2. 快排、归并排、堆排
3. 图论
4. 线段树

#### 1.2 STL巩固

1. 自定义排序：sort/priority_queue/set/map √
2. string √
3. lower_bound/upper_bound √
4. unique
5. multi_set/multi_map

### 2 品味主题

值得反复看的主题：

1. 回溯：总结写递归回溯的套路

2. 单调栈

3. 图论

### 3 品味题目

#### 3.1 单调栈

题目：84
想要O(N)的时间复杂度，牺牲空间记录信息换取时间
递增栈
**如果发现`heights[i]<heights[stk.top()]`，那么stk.top()这个高度对应的最大矩形就可以确定了：右边界是i，左边界是stk的第二个元素。**
