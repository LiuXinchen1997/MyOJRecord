
## 图论算法

1. dfs

```c++
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define N 10005
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
vector<int> G[N];
int color[N], d[N], f[N], tt;

void dfs_visit(int u)
{
    color[u] = GRAY;
    d[u] = ++tt;
    int v;
    for (int i = 0; i < G[u].size(); i++) {
        if (color[G[u][i]] == WHITE) { dfs_visit(G[u][i]); }
    }
    color[u] = BLACK;
    f[u] = ++tt;
}

void dfs()
{
    // init
    tt = 0;
    for (int i = 1; i <= n; i++) {
        color[i] = WHITE;
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == WHITE) { dfs_visit(i); }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d %d %d\n", i, d[i], f[i]);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u, k;
        scanf(" %d %d", &u, &k);
        for (int j = 1; j <= k; j++) {
            int v; scanf(" %d", &v);
            G[u].push_back(v);
        }
    }

    dfs();

    return 0;
}
```

2. bfs

```c++
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define N 1005
#define WHITE 0
#define GRAY 1
#define BLACK 2
vector<int> G[N];

int color[N], d[N];
int n;

void bfs(int s)
{
    // init
    for (int i = 1; i <= n; i++) {
        color[i] = WHITE;
        d[i] = -1;
    }

    queue<int> q;
    q.push(s);
    d[s] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (color[v] == WHITE) {
                // visit!
                color[v] = GRAY;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
        color[u] = BLACK;
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " " << d[i] << endl;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u, k;
        scanf(" %d %d", &u, &k);
        for (int j = 1; j <= k; j++) {
            int v;
            scanf(" %d", &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }

    bfs(1);

    return 0;
}
```

3. prim

```c++
#include <cstdio>
#include <iostream>

using namespace std;

#define N 1005
#define INF (1<<30)
#define WHITE 0
#define GRAY 1
#define BLACK 2

int graph[N][N];
int n;

int prim(int s)
{
    // init
    int color[N], d[N], f[N];
    for (int i = 1; i <= n; i++) {
        color[i] = WHITE;
        d[i] = INF;
        f[i] = -1;
    }
    d[s] = 0;
    color[s] = GRAY;

    while (1) {
        int u = -1;
        int minu = INF;
        for (int v = 1; v <= n; v++) {
            if (color[v] != BLACK && d[v] < minu) {
                u = v;
                minu = d[v];
            }
        }
        if (u == -1) { break; }
        color[u] = BLACK;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != -1 && color[v] != BLACK && graph[u][v] < d[v]) {
                d[v] = graph[u][v];
                f[v] = u;
                color[v] = GRAY;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] != -1) {
            sum += graph[f[i]][i];
        }
    }
    printf("%d\n", sum);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %d", &graph[i][j]);
        }
    }

    prim(1);

    return 0;
}
```

4. dijkstra

```c++
#include <cstdio>
#include <iostream>

using namespace std;

#define N 1005
#define INF (1<<30)
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
int graph[N][N];
int color[N], d[N], f[N];

void dijkstr(int s)
{
    // init
    for (int i = 0; i < n; i++) {
        color[i] = WHITE;
        d[i] = INF;
        f[i] = -1;
    }

    d[s] = 0;
    color[s] = GRAY;
    while (1) {
        int u = -1;
        int minu = INF;
        for (int i = 0; i < n; i++) {
            if (color[i] != BLACK && d[i] < minu) {
                u = i;
                minu = d[i];
            }
        }

        if (-1 == u) { break; }
        color[u] = BLACK;
        for (int v = 0; v < n; v++) {
            if (color[v] != BLACK && graph[u][v] != INF) {
                if (d[u] + graph[u][v] < d[v]) {
                    d[v] = d[u] + graph[u][v];
                    f[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", i, d[i]);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < n; i++) {
        int u, k;
        scanf(" %d %d", &u, &k);

        for (int j = 1; j <= k; j++) {
            int v, w;
            scanf(" %d %d", &v, &w);
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    dijkstr(0);

    return 0;
}
```

5. disset（并查集）

```c++
#include <iostream>
#include <cstdio>

using namespace std;

#define N 1005

int f[N];
int rankk[N];
int n, m;

void make_set(int n)
{
    for (int i = 0; i < n; i++) {
        f[i] = i;
        rankk[i] = 1;
    }
}

int find_f(int i)
{
    if (i != f[i]) {
        f[i] = find_f(f[i]);
    }

    return f[i];
}

void union_set(int x, int y)
{
    x = find_f(x);
    y = find_f(y);
    if (rankk[x] < rankk[y]) {
        f[x] = y;
    } else {
        f[y] = x;
        if (rankk[x] == rankk[y]) {
            rankk[x]++;
        }
    }
}

bool same(int x, int y)
{
    return find_f(x) == find_f(y);
}

int main()
{
    scanf("%d %d", &n, &m);

    // init
    make_set(n);

    for (int i = 1; i <= m; i++) {
        int type, x, y;
        scanf(" %d %d %d", &type, &x, &y);
        if (0 == type) {
            union_set(x, y);
        } else {
            if (same(x, y)) {
                printf("%d\n", 1);
            } else {
                printf("%d\n", 0);
            }
        }
    }

    return 0;
}
```

6. floyd

```c++
#include <cstdio>
#include <iostream>

using namespace std;

#define N 1005
#define INF (1<<30)
int graph[N][N];
int n, e;

void floyd()
{
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (graph[i][k] == INF) { continue; }
            for (int j = 1; j <= n; j++) {
                if (graph[k][j] == INF) { continue; }
                if (graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &e);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = (i == j ? 0 : INF);
        }
    }

    for (int i = 1; i <= e; i++) {
        int u, v, w;
        scanf(" %d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }

    floyd();

    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (graph[i][i] < 0) { flag = true; break; }
    }

    if (flag) { cout << "NEG!" << endl; }
    else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j-1) { cout << " "; }
                if (graph[i][j] == INF) {
                    cout << "INF";
                } else {
                    cout << graph[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}
```

7. topo sort

```c++

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define N 1005

int n, e;
vector<int> G[N];
int ind[N];
bool visited[N];
vector<int> out;

void topo()
{
    out.clear();
    memset(visited, 0, sizeof(visited));

    while (out.size() != n) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && ind[i] == 0) {
                out.push_back(i);
                u = i;
                visited[i] = true;

                for (int j = 0; j < G[i].size(); j++) {
                    int v = G[i][j];
                    ind[v]--;
                }
                break;
            }
        }

        if (-1 == u) { break; }
    }

    for (int i = 0; i < out.size(); i++) {
        if (i) { cout << " "; }
        cout << out[i];
    }
    cout << endl;
}


int main()
{
    scanf("%d %d", &n, &e);
    memset(ind, 0, sizeof(ind));

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf(" %d %d", &u, &v);
        G[u].push_back(v);
        ind[v]++;
    }

    topo();

    return 0;
}
```
