#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    if (a < b) return false;
    return true;
}

int main()
{
	int N;
	int k;

	while (scanf("%d %d", &N, &k) != EOF) {
		int v[N];
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}

		sort(v, v+sizeof(v)/sizeof(int), cmp);

		int count = 0;
		int current_k = 0;

		if (k % v[0] == 0) {
            count = k / v[0];
		} else {
            count = k / v[0] + 1;
		}


		/*
		for (int i = N - 1; i >= 0; i --) {
			int new_count = (k - current_k) / v[i];
			count += new_count;
			current_k += new_count * v[i];

			if (current_k < k && i == 0) {
				count ++;
				current_k += v[i];
			}

			if (current_k >= k) {
				break;
			}
		}
        */
		cout << count << endl;
	}
}
