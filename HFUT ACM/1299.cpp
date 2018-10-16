#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

bool isZiMu(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        return true;
    } else {
        return false;
    }
}

string getReverseStr(string str)
{
    string rev_str = "";
    for (int i = str.length()-1; i >= 0; i--) {
        rev_str += str[i];
    }

    return rev_str;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        bool isWord = false;
        string tempWord = "";
        int beginIndex = 0;
        int count = 0;
        for (int i = 0; i < line.length(); i++) {
            if (isZiMu(line[i])) {
                tempWord += line[i];
                if (!isWord) { isWord = true; beginIndex = i; }
                count ++;

                if (line.length()-1 == i) {
                    line = line.replace(beginIndex, count, getReverseStr(tempWord));
                }
            } else {
                isWord = false;
                line = line.replace(beginIndex, count, getReverseStr(tempWord));
                tempWord = "";
                beginIndex ++;
                count = 0;
            }
        }

        cout << line << endl;
    }

    return 0;
}
