#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>

using namespace std;

#define N 105
int data[N];
vector<int> G;

void show(int n)
{
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << data[i];
    }
    cout << endl;
}

// ¼ä¸ôÎªg
void insert_sort(int n, int g)
{
    for (int i = g; i < n; i++) {
        int v = data[i];
        int j = i - g;
        while (j >= 0 && data[j] > v) {
            data[j+g] = data[j];
            j -= g;
        }
        data[j+g] = v;
    }
}

void shell_sort(int n)
{
    for (int h = 1; ; ) {
        if (h > n) { break; }
        G.push_back(h);
        h = 3 * h + 1;
    }

    for (int i = G.size() - 1; i >= 0; i--) {
        insert_sort(n, G[i]);
    }
}

int main()
{
    fstream infile("data.txt");
    int num = 0;
    while (infile) {
        infile >> data[num];
        ++num;
    }
    --num;
    show(num);

    shell_sort(num);
    show(num);
}
