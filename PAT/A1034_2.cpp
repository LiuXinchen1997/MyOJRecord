#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

#define MAXN 2010

map<string, int> str2int;
map<int, string> int2str;
map<string, int> gangs;

int graph[MAXN][MAXN] = {0}, weight[MAXN] = {0};
bool visited[MAXN] = {false};

int numPerson = 0;

int register_name(string name)
{
    if (str2int.find(name) != str2int.end()) { /// �Ѿ�����
        return str2int[name];
    } else {
        str2int[name] = numPerson;
        int2str[numPerson] = name;
        return numPerson++;
    }
}

void dfs(int nowVisit, int& head, int& numOfGang, int& sumWeight)
{
    visited[nowVisit] = true;
    ++ numOfGang;
    if (weight[head] < weight[nowVisit]) { head = nowVisit; }

    for (int i = 0; i < numPerson; i++) {
        if (graph[nowVisit][i] > 0) {
            sumWeight += graph[nowVisit][i]; /// ��������Ϊ�˰��л��ı�Ҳ����
            graph[nowVisit][i] = 0; graph[i][nowVisit] = 0;
            if (!visited[i]) {
                dfs(i, head, numOfGang, sumWeight);
            }
        }
    }
}

void dfs_travel(int k)
{
    for (int i = 0; i < numPerson; i++) {
        if (!visited[i]) {
            int head = i, numOfGang = 0, sumWeight = 0;
            dfs(i, head, numOfGang, sumWeight);

            if (numOfGang > 2 && sumWeight > k) {
                gangs[int2str[head]] = numOfGang;
            }
        }
    }
}

int main()
{
    int n, k;
    // ifstream infile("A1034data.txt");
    // infile >> n >> k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        string name1, name2; int len;
        // infile >> name1 >> name2 >> len;
        cin >> name1 >> name2 >> len;
        int id1 = register_name(name1), id2 = register_name(name2);

        graph[id1][id2] += len; graph[id2][id1] += len;
        weight[id1] += len; weight[id2] += len;
    }

    // ��ʼ����
    dfs_travel(k);

    cout << gangs.size() << endl;
    for (map<string, int>::iterator it = gangs.begin(); it != gangs.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
