#include <iostream>
#include <queue>

using namespace std;

#define N 1010

int graph[N][N] = {0};
bool visited[N] = {false};

int n, L;

void init()
{
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}

struct User {
    int id, level;
    User() {}
    User(int idd, int lev) : id(idd), level(lev) {}
};

int main()
{
    cin >> n >> L;
    for (int i = 1; i <= n; i++) {
        int num; cin >> num;
        for (int j = 1; j <= num; j++) {
            int d; cin >> d;
            graph[d][i] = 1;
        }
    }

    int num; cin >> num;
    for (int i = 1; i <= num; i++) {
        int d; cin >> d;
        int sum = 0, cur_level = 0;
        init();
        queue<User> q;
        q.push(User(d, 0));
        visited[d] = true;
        while (!q.empty()) {
            cur_level = q.front().level;
            if (cur_level == L) { break; }
            int tmp_id = q.front().id; q.pop();
            for (int j = 1; j <= n; j++) {
                if (graph[tmp_id][j] && !visited[j]) {
                    sum++;
                    visited[j] = true;
                    q.push(User(j, cur_level+1));
                }
            }
        }

        cout << sum << endl;
    }

    return 0;
}
