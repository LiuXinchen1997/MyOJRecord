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
    if(r == n) { // �����������Ѿ��ҵ���һ�ֽⷨ
        print();
        ++cnt;
        return;
    }

    for (int i = 0; i < n; ++i) {
        c[r] = i; // ��r�з��ڵ�i��
        int ok = 1;
        for(int j = 0; j < r; ++j) { // �ж���ǰ����зŵĻʺ��Ƿ���ͻ
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
