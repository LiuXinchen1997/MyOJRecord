#include <iostream>

using namespace std;

int str2int(string s)
{
    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        num = num * 10;
        num = num + s[i] - '0';
    }

    return num;
}

int main()
{
    string str;
    while (cin >> str) {
        string s1 = str.substr(0,2);
        string s2 = str.substr(3,2);

        int sum = str2int(s1) + str2int(s2);
        int count = 0;
        while (sum) {
            if (sum % 2 == 1) {
                count ++;
            }
            sum = sum / 2;
        }

        if (count % 2 == 0) {
            cout << "Stay~~" << endl;
        } else {
            cout << "Run!" << endl;
        }
    }
}
