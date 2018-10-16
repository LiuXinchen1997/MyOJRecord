#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

#define N 27
int arr[N][N];
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};

int get_next_dir(int dir)
{
    dir++;
    if (dir > 4) {
        dir = dir % 4;
    }

    return dir;
}

int main()
{
    int n;
    while (cin >> n) {
        memset(arr, 0, sizeof(arr));
        int cur_x = n / 2+1;
        int cur_y = n / 2+1;

        int cur_num = 1;
        arr[cur_x][cur_y] = cur_num;
        int dir = 1;
        while (cur_num < n*n) {
            cur_num++;

            cur_x = cur_x + dx[dir];
            cur_y = cur_y + dy[dir];
            arr[cur_x][cur_y] = cur_num;

            int next_dir = get_next_dir(dir);
            if ( arr[cur_x+dx[next_dir]][cur_y+dy[next_dir]] == 0 ) {
                dir = next_dir;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << setw(4) << arr[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
