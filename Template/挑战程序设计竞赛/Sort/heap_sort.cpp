#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

#define N 105
int data[N];

void show(int n)
{
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << data[i];
    }
    cout << endl;
}

void maxHeap(int i, int num)
{
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest = i;

    if (l <= num && data[l] > data[i]) { largest = l; }
    if (r <= num && data[r] > data[largest]) { largest = r; }

    if (largest != i) {
        int tmp = data[largest]; data[largest] = data[i]; data[i] = tmp;
        maxHeap(largest, num);
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

    // ½¨¶Ñ
    for (int i = num/2-1; i >= 0; i--) {
        maxHeap(i, num);
    }

    // ¶ÑÅÅÐò
    for (int i = num - 1; i >= 0; i--) {
        int tmp = data[i]; data[i] = data[0]; data[0] = tmp;
        maxHeap(0, i-1);
    }

    show(num);
}
