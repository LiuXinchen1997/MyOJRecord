#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define POSSIZE 12
#define TIMESIZE 300005

int max_time;
int a[TIMESIZE][POSSIZE];
//int d[TIMESIZE][POSSIZE];

int max_num_of_2(int a, int b)
{
    if (a >= b) return a;
    return b;
}

int max_num(int a, int b, int c)
{
    if (a >= b && a >= c) { return a; }
    if (b >= a && b >= c) { return b; }
    return c;
}

// i表示时间，j表示位置，模拟数塔问题
/*
int solve(int i, int j)
{
    if (d[i][j] >= 0) return d[i][j];

    if (j == 0) {
        return d[i][j] = a[i][j] + (i==max_time ? 0 : max_num_of_2(solve(i+1,j), solve(i+1,j+1)));
    } else if (j == 10) {
        return d[i][j] = a[i][j] + (i==max_time ? 0 : max_num_of_2(solve(i+1,j), solve(i+1,j-1)));
    }
    return d[i][j] = a[i][j] + (i==max_time ? 0 : max_num(solve(i+1,j-1), solve(i+1,j), solve(i+1,j+1)));
}
*/


int get_res(){
	int i, j, max;
	for (i = max_time - 1; i >= 0; --i){
		a[i][0] = max_num_of_2(a[i+1][0], a[i+1][1]) + a[i][0];
		for (j = 1; j < 10; ++j){
			a[i][j] = max_num(a[i+1][j-1], a[i+1][j], a[i+1][j+1]) + a[i][j];
		}
		a[i][10] = max_num_of_2(a[i+1][10], a[i+1][9]) + a[i][10];
	}
	return a[0][5];
}




int main()
{
    int n;
    int pos;
    int time;

    while(~scanf("%d", &n) && n != 0) {
        max_time = 0;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &pos, &time);
            if (max_time < time) { max_time = time; }
            ++ a[time][pos];
        }
        printf("%d\n", get_res());

        //memset(d, -1, sizeof(d));
        //printf("%d\n", solve(0,5));
    }

    return 0;
}
