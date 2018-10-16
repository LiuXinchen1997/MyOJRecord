#include <iostream>
using namespace std;

int c[9], n = 8, cnt = 0;
void print() {
    for(int i = 0; i < n; ++i){
        for(int j = 0; j<n; ++j){
            if (j == c[i]) cout << j;
        }
    }
    cout << endl;
}

void search(int r) {
    if(r == n) { // 结束搜索，已经找到了一种解法
        print();
        ++cnt;
        return;
    }

    for (int i = 0; i < n; ++i) {
        c[r] = i; // 第r行放在第i列
        int ok = 1;
        for(int j = 0; j < r; ++j) { // 判断与前面的行放的皇后是否会冲突
            if (c[r] == c[j] || r-j == c[r]-c[j] || r-j == c[j]-c[r]) {
                ok = 0;
                break;
            }
        }
        if (ok) search(r+1);
    }
}

int main() {
    search(0);
    return 0;
}
