// 并查集模板
// Graph目录内亦有并查集模板

int n = 100;
vector<int> f(n, 0);
vector<int> rankk(n, 1);

void make_set(int n)
{
    for (int i = 0; i < n; i++) { f[i] = i; }
}

int find(int i)
{
    if (i != f[i]) {
        f[i] = find(f[i]);
    }
    return f[i];
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

void union_set(int x, int y)
{
    x = find(x);
    y = find(y);
    if (rankk[x] < rankk[y]) {
        f[x] = y;
    } else {
        f[y] = x;
        if (rankk[x] == rankk[y]) {
            rankk[x] += 1;
        }
    }
}
