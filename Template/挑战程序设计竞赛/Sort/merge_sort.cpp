#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

#define N 105
#define MAXN 20000000
int data[N];
int L[N/2+2];
int R[N/2+2];

void show(int n)
{
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << data[i];
    }
    cout << endl;
}

void merge_op(int n, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) { L[i] = data[left+i]; }
    for (int i = 0; i < n2; i++) { R[i] = data[mid+i]; }
    L[n1] = MAXN;
    R[n2] = MAXN;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            data[k] = L[i++];
        } else {
            data[k] = R[j++];
        }
    }
}

void merge_sort(int n, int left, int right)
{
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        merge_sort(n, left, mid);
        merge_sort(n, mid, right);
        merge_op(n, left, mid, right);
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

    merge_sort(num, 0, num);
    show(num);
}
