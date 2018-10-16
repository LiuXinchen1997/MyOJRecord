#include <iostream>
#include <stdio.h>
#include <sstream>

using namespace std;

int calcBitSum(int num)
{
    stringstream ss;
    string numstr;
    ss << num;
    ss >> numstr;

    int sum = 0;
    for (int i = 0; i < numstr.length(); i++) { //
        sum += (numstr[i] - '0');
    }

    return sum;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF) { //
        int sum = calcBitSum(n);

        if (n % sum == 0) {
            printf("yes\n");
        } else {
            printf("no\n"); //
        }
    }

    return 0;
}
