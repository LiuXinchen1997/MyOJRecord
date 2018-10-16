#include <iostream>
#include <stdio.h>

using namespace std;

bool isHuiWen(string s)
{
    for (int i = 0, j = s.length()-1; i < s.length(); i++, j--) {
        if (s[i] != s[j]) return false;
    }

    return true;
}

int main()
{
    string line;
    getline(cin, line);
    while (line != "#") {
        string huiwenstr = "";
        for (int i = 0; i < line.length(); i++) {
            for (int j = 1; j <= line.length() - i; j++) {
                string sub = line.substr(i, j);

                if (isHuiWen(sub) && huiwenstr.length() < sub.length()) {
                    huiwenstr = sub;
                }
            }
        }

        cout << huiwenstr << endl;
        getline(cin, line);
    }

    return 0;
}
