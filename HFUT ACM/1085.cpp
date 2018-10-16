#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int getweishu(__int64 num)
{
    int weishu = 0;
    while (num != 0) {
        weishu++;
        num /= 10;
    }

    return weishu;
}

int main()
{
    int n;
    while (cin >> n) {
        priority_queue<__int64> pq;
        priority_queue<__int64> pq2;
        for (int i = 1; i <= n; i++) {
            __int64 tmp;
            cin >> tmp;
            pq.push(tmp);
            pq2.push(-1*tmp);
        }

        while (true) {
            __int64 a = pq.top(); pq.pop(); n--;
            __int64 b = pq.top(); pq.pop(); n--;
            __int64 a2 = -1 * pq2.top(); pq2.pop();
            __int64 b2 = -1 * pq2.top(); pq2.pop();

            __int64 num = a*b+1;
            pq.push(num); n++;
            __int64 num2 = -1*(a2*b2+1);
            pq2.push(num2);
            if (n == 1) { break; }
        }

        __int64 num1 = pq.top(); pq.pop();
        __int64 num2 = -1*pq2.top(); pq2.pop();

        __int64 M = num1 - num2;
        if (M < 0) { M = -M; }
        cout << getweishu(M) << endl;
        cout << M << endl;
    }

    return 0;
}
