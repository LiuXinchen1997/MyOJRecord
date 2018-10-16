#include<iostream>
#include<algorithm>
using namespace std;

struct Point
{
    int x, y;
} ps[50002];

int top, stack[50002]; // 凸包的点存在于stack[]中

// 求点a和点b的距离
inline double dis(const Point &a, const Point &b)
{
    return (a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y);
}

inline int max(int a, int b)
{
    return a > b ? a : b;
}

// 计算叉乘--线段旋转方向和对应的四边形的面积--返回(p1-p0)*(p2-p0)叉积
// 如果叉积为正，则p0p1在p0p2的顺时针方向 if(x==0)共线
inline int xmult(const Point &p1, const Point &p2 , const Point &p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y) - (p1.y-p0.y)*(p2.x-p0.x);
}

int cmp(const void* a, const void* b) // 逆时针排序 返回正数要交换
{
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    int ans = xmult(*p1, *p2, ps[0]);  // 向量叉乘
    if (ans < 0)   // p0p1线段在p0p2线段的上方，需要交换
        return 1;
    else if(ans == 0 && ( (*p1).x >= (*p2).x))  //斜率相等时，距离近的点在先
        return 1;
    else
        return -1;
}

void andrew(int n) //安德鲁算法形成凸包
{
    qsort(ps+1, n-1, sizeof(Point), cmp);
    stack[0] = 0, stack[1] = 1;
    top = 1;

    // 构建凸包上部节点
    for(int i = 2 ; i < n ; ++i)
    {
        while(top > 0 && xmult(ps[stack[top]], ps[i], ps[stack[top-1]]) <= 0)
            top--;  //顺时针方向--删除栈顶元素
        stack[++top] = i;    //新元素入栈
    }

    // 构建凸包下部节点
    int temp = top;
    for(int i = n-2; i >= 0 ; --i)
    {
        while (top > temp && xmult(ps[stack[top]] , ps[i] , ps[stack[top-1]]) <= 0)
            top--;
        stack[++top] = i;    //新元素入栈
    }
}

int rotate_kake() // 旋转卡壳
{
    int q = 1;
    int ans = 0;
    stack[top] = 0;
    for (int i = 0 ; i < top ; i++) // 选边
    {
        while( xmult(ps[stack[i+1]], ps[stack[q+1]], ps[stack[i]]) > xmult(ps[stack[i+1]], ps[stack[q]], ps[stack[i]]) )
            q = (q+1)%(top);
        ans = max(ans, max(dis(ps[stack[i]], ps[stack[q]]), dis(ps[stack[i+1]], ps[stack[q]])));
    }
    return ans;
}

int main()
{
    int n;
    while(cin >> n)
    {
        int leftdown = 0; // 标记最左下角的点
        for(int i = 0 ; i < n ; ++i)
        {
            scanf("%d %d", &ps[i].x, &ps[i].y);
            if (ps[i].y < ps[leftdown].y || (ps[i].y == ps[leftdown].y && ps[i].x < ps[leftdown].x))  //找到最左下角的点
                leftdown = i;
        }
        swap(ps[0], ps[leftdown]);
        andrew(n);
        printf("%d\n", rotate_kake());
    }
    return 0;
}

