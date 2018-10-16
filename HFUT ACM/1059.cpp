#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        map<int,int> mmm;

        int tmp_n = n;
        for (int i = 2; i <= n; i++) {
            if (1 == tmp_n) { break; }

            while (tmp_n % i == 0) {
                mmm[i]++;
                tmp_n /= i;
            }
        }

        map<int,int>::iterator it = mmm.begin();
        while (it != mmm.end()) {
            if (it == mmm.begin()) {
                cout << it->first << "^" << it->second;
            } else {
                cout << "X" << it->first << "^" << it->second;
            }

            it++;
        }
        cout << endl;


    }

    return 0;
}