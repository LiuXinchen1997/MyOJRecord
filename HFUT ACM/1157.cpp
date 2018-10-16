#include <iostream>
#include <cstring>

using namespace std;

#define N 105
#define INF (1<<14)
int graph[N][N];
int visited[N];
int d[N];

int min_of_2(int a, int b)
{
    if (a <= b) {
        return a;
    }
    return b;
}

int main()
{
    int n;

    while(cin >> n) {
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> graph[i][j];
            }
            d[i] = INF;
        }

        int q;
        cin >> q;
        for (int i = 1; i <= q; i++) {
            int num1, num2;
            cin >> num1 >> num2;
            visited[num1] = 1;
            for (int j = 1; j <= n; j++) {
                int tmp = min_of_2(graph[num1][j], graph[j][num1]);
                if (!visited[j] && tmp < d[j]) {
                    d[j] = tmp;
                }
            }

            visited[num2] = 1;
            for (int j = 1; j <= n; j++) {
                int tmp = min_of_2(graph[num2][j], graph[j][num2]);
                if (!visited[j] && tmp < d[j]) {
                    d[j] = tmp;
                }
            }
        }

        int cost = 0;
        while (1) {
            int min_value = INF;
            int u = -1;
            for (int i = 1; i <= n; i++) {
                if (d[i] < min_value && !visited[i]) {
                    min_value = d[i];
                    u = i;
                }
            }

            if (u == -1) { break; }
            visited[u] = 1;
            cost += d[u];

            for (int v = 1; v <= n; v++) {
                int tmp = min_of_2(graph[u][v], graph[v][u]);
                if (!visited[v] && tmp < d[v]) {
                    d[v] = tmp;
                }
            }
        }
        cout << cost << endl;
    }

    return 0;
}
