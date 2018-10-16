#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

int main()
{
    char word[11];
    while(cin >> word) {
        int wordlen = strlen(word);
        for (int i = 0; i < wordlen; i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                word[i] = word[i] + 32;
            }
        }

        char text[100001];
        char ch; int num = 0;
        while (cin >> ch) {
            if (ch >= 'A' && ch <= 'Z') {
                ch = ch + 32;
            }

            text[num] = ch;
            num++;
        }

        int count = 0;
        for (int i = 0; i <= num; i++) {
            for (int j = 0, k = i; j < wordlen;) {
                if ((j == wordlen - 1) && (word[j] == text[k])) {
                    count ++;
                    break;
                }

                if (word[j++] != text[k++]) {
                    break;
                }
            }
        }

        cout << count << endl;
    }
}
