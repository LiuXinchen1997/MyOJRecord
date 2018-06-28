#include <stdio.h>

void Union(int a, int b);

void p(int a);

int find(int a);

int pre[1010] = {0};

int main()
{
	int n, m, c, d, i, cnt;
	while (scanf("%d %d", &n, &m) != EOF) {
		if (m == 0 && n == 0) break;
		if (m > n - 1) {
			for (i = 0; i < m; i++) {
				scanf("%d%d", &c, &d);
			}
			printf("No\n");
		}
		else {
            cnt = 0;
			p(n);
			for (i = 0; i < m; i++) {
				scanf("%d%d", &c, &d);
				Union(c, d);
			}
			for(i = 0; i < n; i++) {
				if (i == pre[i])
					cnt++;
			}
			if (cnt == 1)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}

void p(int a)
{
	for (int i = 0; i < a; i++) {
		pre[i] = i;
	}
}

int find(int a)
{
	int r = a;
	while (r != pre[r]) {
		r = pre[r];
	}
	return r;
}

void Union(int a,int b) {
	int fa,fb;
	fa = find(a);
	fb = find(b);
	if (fa!=fb) pre[fb]=fa;
}
