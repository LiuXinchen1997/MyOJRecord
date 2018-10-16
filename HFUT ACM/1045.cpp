#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
    int n;
    while (~scanf("%d", &n)) {
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            num = -1 * num;
            pq.push(num);
        }

        int sum = 0;
        while (pq.size() > 1) {
            int num1 = pq.top(); pq.pop();
            int num2 = pq.top(); pq.pop();

            sum += num1; sum += num2;
            pq.push(num1+num2);
        }

        sum = -1 * sum;
        printf("%d\n", sum);
    }

    return 0;
}
