#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main()
{
    int num;
    while (cin >> num) {
        map<int, int> m;
        int tar = num;
        for (int i = 2; i <= tar; i++) {
            if (num == 1) { break; }
            while (num % i == 0) {
                m[i] ++;
                num = num / i;
            }
        }

        string s = "";
        auto it = m.begin();
        while (it != m.end()) {
            stringstream ss, ss2;
            string temp;
            ss << it->first;
            ss >> temp;
            s += temp;
            s += "^";

            ss2 << it->second;
            ss2 >> temp;
            s += temp;
            s += "X";

            it ++;
        }

        s.resize(s.length()-1);
        cout << s << endl;
    }


    return 0;
}
