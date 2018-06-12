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
    show(num);

    /*
    for (int i = 0; i < num; i++) {
        for (int j = num-1; j >= i+1; j--) {
            if (data[j] < data[j-1]) {9
                int tmp = data[j];
                data[j] = data[j-1];
                data[j-1] = tmp;
            }
        }
    }
    */

    // ÓÅ»¯µÄbubble sort
    bool flag = true;
    for (int i = 0; flag; i++) {
        flag = false;
        for (int j = num-1; j >= i+1; j--) {
            if (data[j] < data[j-1]) {
                flag = true;
                int tmp = data[j];
                data[j] = data[j-1];
                data[j-1] = tmp;
            }
        }
    }

    show(num);
}
