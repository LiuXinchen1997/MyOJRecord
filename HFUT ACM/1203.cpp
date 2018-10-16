// 未使用Lazy Tag优化

#include <iostream>
using namespace std;

#define MAXN 400010

struct Node {
    int left, right;
    int sum;
} nodes[MAXN];

void build(int l, int r, int i)
{
    nodes[i].left = l;
    nodes[i].right = r;
    nodes[i].sum = 0;

    if (l == r) { return; }
    int mid = (l + r) >> 1;
    build(l, mid, i<<1);
    build(mid+1, r, (i<<1)+1);
}


void update(int l, int r, int val, int i)
{
    nodes[i].sum += val;
    if (nodes[i].left == nodes[i].right) { return; }
    int mid = (nodes[i].left + nodes[i].right) >> 1;
    if (r <= mid) {
        update(l, r, val, i << 1);
    } else if (l > mid) {
        update(l, r, val, (i<<1)+1);
    } else {
        update(l, mid, val, i<<1);
        update(mid+1, r, val, (i<<1)+1);
    }
}


int query(int l, int r, int i)
{
    if (l == nodes[i].left && r == nodes[i].right) {
        return nodes[i].sum;
    }

    int mid = (nodes[i].left + nodes[i].right) >> 1;
    if (r <= mid) {
        return query(l, r, i<<1);
    }

    if (l > mid) {
        return query(l, r, (i<<1)+1);
    } else {
        return query(l, mid, i<<1) + query(mid+1, r, (i<<1)+1);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    build(1, n, 1);
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        update(i, i, t, 1);
    }

    for (int i = 1; i <= m; i++) {
        char a; cin >> a;
        if ('Q' == a) {
            int l, r;
            cin >> l >> r;
            cout << query(l, r, 1) << endl;
        } else if ('C' == a) {
            int l, r, c;
            cin >> l >> r >> c;
            update(l, r, c, 1);
        }
    }

    return 0;
}
