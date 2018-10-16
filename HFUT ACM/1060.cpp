#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <stdlib.h>
#include <stack>
#include <queue>

using namespace std;


void printAllOutStackSeq (queue<int> inQueue, int n, stack<int> st, queue<int> out)
{
	if (n <= 0 || (inQueue.empty() && st.empty() && out.empty())) {
		return;
	}

	if (out.size() == n) {
		while (!out.empty()) {
			cout << out.front();
			out.pop();
		}

		cout << endl;
		return;
	}

	stack<int> stCopy = st;  // 备份一下，否则储转
	queue<int> outCopy = out;

	if (!st.empty()) // 出栈，将元素出栈，push到结果队列中
	{
		out.push(st.top());
		st.pop();
		printAllOutStackSeq(inQueue, n, st, out);
	}


	if (!inQueue.empty()) // 入栈，将输入队列出队，进行入栈
	{
		stCopy.push(inQueue.front());
		inQueue.pop();
		printAllOutStackSeq(inQueue, n, stCopy, outCopy);
	}

	return;
}


int main()
{
	int n = 0;
	while (cin >> n) {
        queue<int> inQueue;

        for( int i = 1; i <= n; i++ ) {
            inQueue.push(i);
        }

        stack<int> st;
        queue<int> out;

        printAllOutStackSeq(inQueue, n, st, out);
	}
	return 0;
}
