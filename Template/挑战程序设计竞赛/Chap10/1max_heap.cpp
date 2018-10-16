#include <iostream>
using namespace std;
#define N 200000

int h, A[N+1];

void swap(int& n1, int& n2)
{
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
}

void max_heap(int i)
{
    int l = 2 * i;
    int r = 2 * i + 1;

    int largest;
    if (l <= h && A[l] > A[i]) { largest = l; }
    else { largest = i; }
    if (r <= h && A[r] > A[largest]) { largest = r; }

    if (largest != i) {
        swap(A[i], A[largest]);
        max_heap(largest);
    }
}

int main()
{
    cin >> h;
    for (int i = 1; i <= h; i++) { cin >> A[i]; }

    for (int i = h/2; i >= 1; i--) { max_heap(i); }

    for (int i = 1; i <= h; i++) {
        if (i-1) cout << " ";
        cout << A[i];
    }
    cout << endl;

    return 0;
}
