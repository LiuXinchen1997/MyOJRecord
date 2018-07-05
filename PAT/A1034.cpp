#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> str2int; // 名称-->编号
map<int, string> int2str; // 编号-->名称

map<string, int> gangs; // Head-->num of gang

#define INF (1<<30)
#define MAXN 2010

int graph[MAXN][MAXN] = {0};
int weight[MAXN] = {0}; /// 用于找到点权最大的边
int numPerson = 0;
bool visited[MAXN] = {false};

int register_name(string name)
{
    if (str2int.find(name) != str2int.end()) {
        return str2int[name];
    } else {
        str2int[name] = numPerson;
        int2str[numPerson] = name;
        return numPerson++;
    }
}

void dfs(int nowVisit, int& numOfGang, int& head, int& sumWeight)
{
    visited[nowVisit] = true;
    numOfGang++;
    if (weight[head] < weight[nowVisit]) {
        head = nowVisit;
    }

    for (int i = 0; i < numPerson; i++) {
        if (graph[nowVisit][i] > 0) { /// 这里需要考虑有环的情况
            sumWeight += graph[nowVisit][i];
            graph[nowVisit][i] = 0; graph[i][nowVisit] = 0;
            if (!visited[i]) {
                dfs(i, numOfGang, head, sumWeight);
            }
        }
    }
}

void dfs_travel(int k) /// 阈值k
{
    for (int i = 0; i < numPerson; i++) {
        if (!visited[i]) {
            int head = i, numOfGane = 0, sumWeight = 0;
            dfs(i, numOfGane, head, sumWeight);
            if (numOfGane > 2 && sumWeight > k) {
                gangs[int2str[head]] = numOfGane;
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        string name1, name2; int len;
        cin >> name1 >> name2 >> len;
        int id1 = register_name(name1);
        int id2 = register_name(name2);
        graph[id1][id2] += len; graph[id2][id1] += len;
        weight[id1] += len; weight[id2] += len;
    }
    dfs_travel(k);

    cout << gangs.size() << endl;
    for (map<string, int>::iterator it = gangs.begin(); it != gangs.end(); it++) {
        cout << it-> first << " " << it->second << endl;
    }

    return 0;
}
