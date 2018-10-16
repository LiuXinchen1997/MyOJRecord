#include <iostream>
using namespace std;
#define SIZE 105
#define MAX (1 << 21)
int graph[SIZE][SIZE];
int d[SIZE];
bool visited[SIZE];
int p[SIZE];

void init(int n)
{
    for (int i = 0; i < n; i++) {
        d[i] = MAX;
        p[i] = -1;
        visited[i] = false;
    }
}

int prim(int n)
{
    init(n);

    d[0] = 0;
    while (true) {
        int minv = MAX;
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (minv > d[i] && !visited[i]) {
                u = i;
                minv = d[i];
            }
        }

        if (-1 == u) { break; }
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != MAX) {
                if (d[v] > graph[u][v]) {
                    d[v] = graph[u][v];
                    p[v] = u;
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] != -1) sum += graph[i][p[i]];
    }

    return sum;
}

int main()
{
    int num;
	while(cin >> num)
	{
		for (int i = 0; i < num; i++)
			for(int j = 0; j < num; j++)
				cin >> graph[i][j];
		cout << prim(num) << endl;
	}

    return 0;
}
