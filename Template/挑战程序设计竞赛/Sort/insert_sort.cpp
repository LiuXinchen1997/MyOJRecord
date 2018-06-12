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

int main()
{
    fstream infile("data.txt");
    int num = 0;
    while (infile) {
        infile >> data[num];
        ++num;
    }
    --num;

    for (int i = 0; i < num-1; i++) {
        int v = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > v) {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = v;
    }

    show(num);
}
