#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <map>

using namespace std;

string expr;
struct Node {
    bool flag; // true for number, false for operator
    double num;
    char op;
};
stack<Node> ops; // 操作符栈
queue<Node> q; // 后缀表达式
map<char, int> pri_m;

int convert2num(string str)
{
    int num = 0;
    for (int i = 0; i < str.size(); i++) {
        num *= 10;
        num += (str[i] - '0');
    }

    return num;
}


int main()
{
    pri_m['!'] = 0;
    pri_m['+'] = pri_m['-'] = 1;
    pri_m['*'] = pri_m['/'] = 2;

    while (getline(cin, expr), expr != "0") {
        Node tn; tn.flag = false; tn.op = '!';
        ops.push(tn);
        stringstream ss;
        ss << expr;
        string fag;
        while (ss >> fag) {
            Node node;
            if (fag[0] >= '0' && fag[0] <= '9') {
                node.flag = true;
                node.num = convert2num(fag);
                q.push(node);
            } else {
                node.flag = false;
                node.op = fag[0];
                if (pri_m[node.op] > pri_m[ops.top().op]) {
                    ops.push(node);
                } else {
                    while (pri_m[node.op] <= pri_m[ops.top().op]) {
                        q.push(ops.top());
                        ops.pop();
                    }
                    ops.push(node);
                }
            }
        }
        while (ops.top().op != '!') {
            q.push(ops.top());
            ops.pop();
        }

        /*
        while (!q.empty()) {
            if (q.front().flag) { cout << q.front().num << endl; }
            else { cout << q.front().op << endl; }
            q.pop();
        }
        */

        // 后缀表达式已经构造完成，接下来需要开始计算后缀表达式
        stack<double> nums;
        while (!q.empty()) {
            if (q.front().flag) {
                nums.push(q.front().num);
                q.pop();
            } else {
                double tmp2 = nums.top(); nums.pop();
                double tmp1 = nums.top(); nums.pop();
                switch (q.front().op) {
                case '+':
                    nums.push(tmp1 + tmp2); break;
                case '-':
                    nums.push(tmp1 - tmp2); break;
                case '*':
                    nums.push(tmp1 * tmp2); break;
                case '/':
                    nums.push(tmp1 / tmp2); break;
                }
                q.pop();
            }
        }

        cout << fixed << setprecision(2) << nums.top() << endl;
    }

    return 0;
}
