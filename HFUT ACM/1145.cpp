#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

#define MAXN 100005
#define INF (1<<22)


int main()
{
    int n;
    while(~scanf("%d", &n)) {
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            num = -1 * num;
            pq.push(num);
        }

        int sum = 0;
        while (pq.size() > 1) {
            int num1 = pq.top();
            pq.pop();

            int num2 = pq.top();
            pq.pop();

            sum += num1; sum += num2;
            pq.push(num1+num2);
        }

        sum = -1 * sum;
        printf("%d\n", sum);
    }




    /*
    char cost[MAXN][MAXN];  //cost[i][j]表示第i个中子星到第j个中子星之间全部合并
                        //最少共需要多少能量
    char sum[MAXN][MAXN];

    memset(cost, 0, sizeof(cost));
    memset(sum, 0, sizeof(sum));
    int t;
    while (~scanf("%d", &t)) {
        for (int i = 1; i <= t; i++) {
            //scanf("%d", nums+i);
            //sum[i][i] = nums[i];
            cin >> sum[i][i];
            cost[i][i] = 0;
        }

        for (int l = 2; l <= t; l++) {
            for (int i = 1; i <= t-l+1; i++) {
                int j = i + l - 1;
                cost[i][j] = INF;
                sum[i][j] = sum[i][j-1] + sum[j][j];
                for (int k = i+1; k < j; k++) {
                    cost[i][j] = min_of_2(cost[i][k]+cost[k+1][j]+sum[i][k]+sum[k+1][j], cost[i][j]);
                }
            }
        }

        printf("%d\n", cost[1][t]);
    }
*/
    return 0;
}
