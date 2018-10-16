#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

char word[15];
char text[100005];

bool isZiMu(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) { return true; }
    return false;
}

bool isUpperCase(char ch)
{
    if (ch >= 'A' && ch <= 'Z') { return true; }
    else { return false; }
}

void lower_case(int text_len, int word_len)
{
    for (int i = 0; i < word_len; i++) {
        if (isUpperCase(word[i])) { word[i] += 32; }
    }

    for (int i = 0; i < text_len; i++) {
        if (isUpperCase(text[i])) { text[i] += 32; }
    }
}

int main()
{
    while (gets(word)) {
        gets(text);
        lower_case(strlen(text), strlen(word));
        int wordlen = strlen(word);

        char* p_text = text;

        int count = 0;
        p_text = strstr(p_text, word);

        while ((void*)p_text != NULL) {
            if (p_text == text) { count++; }
            else if( !isZiMu(*(p_text-1)) && !isZiMu(*(p_text+wordlen)) ) {
                count ++;
            }
            p_text ++;
            p_text = strstr(p_text, word);
        };
        cout << count << endl;
    }

    return 0;
}
