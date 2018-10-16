#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        int blank_num = n / 2;
        for (int i = 1; i <= n/2+1; i++) {
            for (int j = 1; j <= blank_num; j++) {
                cout << " ";
            }
            cout << "*";
            if (i != 1) {
                for (int j = 1; j <= (i-1)*2-1; j++) {
                    cout << " ";
                }
                cout << "*" << endl;
            } else {
                cout << endl;
            }

            blank_num -= 1;
        }

        for (int i = 1; i <= n/2; i++) {
            for (int j = 1; j <= i; j++) cout << " ";
            cout << "*";
            if (i == n/2) {
                cout << endl;
            } else {
                for (int j = 1; j <= n-2-2*i; j++) cout << " ";
                cout << "*" << endl;
            }
        }

        cout << endl;
    }


    return 0;
}
