#include<iostream>
#include<algorithm>
#include <stdio.h>
using namespace std;

struct Point
{
	int x , y;
} ps[50002];

int top, stack[50002];    // ͹���ĵ������stack[]��

// ���a�͵�b�ľ���
inline double dis(const Point &a , const Point &b)
{
	return (a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y);
}

inline int max(int a , int b)
{
	return a > b ? a : b;
}

// ������--�߶���ת����Ͷ�Ӧ���ı��ε����--����(p1-p0)*(p2-p0)���
// ������Ϊ������p0p1��p0p2��˳ʱ�뷽�� if(x==0)����
inline int xmult(const Point &p1 , const Point &p2 , const Point &p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y) - (p1.y-p0.y)*(p2.x-p0.x);
}

int cmp(const void* a, const void* b) // ��ʱ������ ��������Ҫ����
{
	Point* p1 = (Point*)a;
	Point* p2 = (Point*)b;
	int ans = xmult(*p1 , *p2 , ps[0]);   // �������
	if (ans < 0)   // p0p1�߶���p0p2�߶ε��Ϸ�����Ҫ����
		return 1;
	else if(ans == 0 && ( (*p1).x >= (*p2).x))     //б�����ʱ��������ĵ�����
		return 1;
	else
		return -1;
}

void andrew(int n) //����³�㷨�γ�͹��
{
	qsort(ps+1, n-1, sizeof(Point), cmp);
	stack[0] = 0, stack[1] = 1;
	top = 1;

	// ����͹���ϲ��ڵ�
	for(int i = 2 ; i < n ; ++i)
	{
		while(top > 0 && xmult(ps[stack[top]], ps[i], ps[stack[top-1]]) <= 0)
			top--;  //˳ʱ�뷽��--ɾ��ջ��Ԫ��
		stack[++top] = i;    //��Ԫ����ջ
	}

	// ����͹���²��ڵ�
	int temp = top;
	for(int i = n-2; i >= 0 ; --i)
	{
		while (top > temp && xmult(ps[stack[top]] , ps[i] , ps[stack[top-1]]) <= 0)
			top--;
		stack[++top] = i;    //��Ԫ����ջ
	}
}

int rotate_kake()  // ��ת����
{
	int q = 1;
	int ans = 0;
	stack[top] = 0;
	for (int i = 0 ; i < top ; i++) // ѡ��
	{
		while( xmult(ps[stack[i+1]], ps[stack[q+1]], ps[stack[i]]) > xmult(ps[stack[i+1]], ps[stack[q]], ps[stack[i]]) )
			q = (q+1)%(top);
		ans = max(ans, max(dis(ps[stack[i]], ps[stack[q]]), dis(ps[stack[i+1]], ps[stack[q]])));
	}
	return ans;
}

int main()
{
	int n;
	while(cin >> n)
	{
		int leftdown = 0; // ��������½ǵĵ�
		for(int i = 0 ; i < n ; ++i)
		{
			scanf("%d %d", &ps[i].x, &ps[i].y);
			if (ps[i].y < ps[leftdown].y || (ps[i].y == ps[leftdown].y && ps[i].x < ps[leftdown].x))  //�ҵ������½ǵĵ�
				leftdown = i;
		}
		swap(ps[0], ps[leftdown]);
		andrew(n);
		printf("%d\n", rotate_kake());
	}
	return 0;
}
