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

void partition( int* a, int s, int t, int* cutPoint )
{
    int x = a[s];
    // srand((unsigned int)time(NULL));
    // int r = ( rand() % ( t - s + 1 ) ) + s;
    // int x = a[r];
    // int temp = a[r]; a[r] = a[s]; a[s] = temp;

    int i = s; int j = t;
    while ( i != j ) {
        while ( i < j && a[j] > x ) j--;
        if ( i < j ) { a[i] = a[j]; i++; }
        while ( i < j && a[i] < x ) i++;
        if ( i < j ) { a[j] = a[i]; j--; }
    }
    a[i] = x; *cutPoint = i;
}

void quick_sort( int* a, int s, int t )
{
    if ( s < t ) {
        int *i = new int;
        partition( a, s, t, i );
        quick_sort( a, s, *i-1 );
        quick_sort( a, *i+1, t );
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

    quick_sort(data, 0, num);
    show(num);
}
