#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=20000+100;//�����Ŀ
int tree[maxn<<4];
int li[maxn],ri[maxn];
int lisan[3*maxn];
bool visit[3*maxn];
void pushdown(int p) {
    tree[p<<1] = tree[(p<<1)|1] = tree[p];
    tree[p] = -1;
}

void update(int p, int l, int r, int x, int y, int v)
{
    if(x <= l && y >= r) { // �����ǰ�ڵ�������Ⱦɫ�����һ���֣���ֱ��Ⱦɫ
        tree[p] = v;
        return;
    }

    // ��ʱȾɫ����ͽڵ������������һ�������غϵģ�������Ҫ���²����Ⱦɫ
    if (tree[p] != -1) pushdown(p);

    int mid = (l+r) >> 1;
    if (y <= mid) update(p<<1, l, mid, x, y, v);
    else if (x > mid) update((p<<1)|1, mid+1, r, x, y, v);
    else update(p<<1, l, mid, x, mid, v), update((p<<1)|1, mid+1, r, mid+1, y, v);
}

int ans;
void query(int p,int l,int r)
{
    if (tree[p] != -1) {
        if (!visit[tree[p]]) {
            ans++;
            visit[tree[p]] = true;
        }
        return;
    }

    if (l == r) return;

    int mid = (l+r) >> 1;
    query(p<<1, l, mid);
    query((p<<1)|1, mid+1, r);
}

int main()
{
    int T;
    scanf("%d", &T);
    int n;
    while(T--) {
        scanf("%d", &n);
        memset(tree, -1, sizeof(tree));
        memset(visit, false, sizeof(visit));
        int tot = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &li[i], &ri[i]);
            lisan[tot++] = li[i];
            lisan[tot++] = ri[i];
        }

        sort(lisan, lisan + tot); //tot�����鳤��
        int m = unique(lisan, lisan + tot) - lisan; // ȥ��
        int t = m;
        for(int i = 1;i < t; i++) {
            if(lisan[i] - lisan[i-1] > 1) { lisan[m++]=lisan[i-1]+1; }
        }
        sort(lisan, lisan + m);

        // ��ʼȾɫ
        for (int i = 0; i < n; i++) {
            // �ҵ���i������棬��߽��Ӧ����ɢ������������
            int x = lower_bound(lisan, lisan+m, li[i]) - lisan;
            // �ҵ���i������棬�ұ߽��Ӧ����ɢ������������
            int y = lower_bound(lisan, lisan+m, ri[i]) - lisan;
            update(1, 0, m-1, x, y, i);
        }
        ans = 0;
        query(1, 0, m-1);
        printf("%d\n", ans);
    }
}
