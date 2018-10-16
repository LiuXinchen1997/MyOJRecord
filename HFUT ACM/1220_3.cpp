#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

char word[15];
char text[100005];

bool isZiMu(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) { return true; }
    return false;
}

bool isUpperCase(char ch)
{
    if (ch >= 'A' && ch <= 'Z') { return true; }
    else { return false; }
}

void lower_case(int text_len, int word_len)
{
    for (int i = 0; i < word_len; i++) {
        if (isUpperCase(word[i])) { word[i] += 32; }
    }

    for (int i = 0; i < text_len; i++) {
        if (isUpperCase(text[i])) { text[i] += 32; }
    }
}

int main()
{
    while (gets(word)) {
        gets(text);
        lower_case(strlen(text), strlen(word));
        string w(word);
        string t(text);

        int beginIndex = 0;
        bool start = false;
        int count = 0;
        for (int i = 0; i < t.length(); i++) {
            if (isZiMu(t[i]) && !start) { beginIndex = i; start = true; }
            if (!isZiMu(t[i]) && start) {
                string temp(t, beginIndex, i-beginIndex);
                if (temp == w) { count++; }

                start = false;
                beginIndex = i+1;
            } else if (start && isZiMu(t[i]) && i == t.length()-1) {
                string temp(t, beginIndex, i-beginIndex+1);
                if (temp == w) { count++; }
            }
        }

        cout << count << endl;
    }

    return 0;
}
