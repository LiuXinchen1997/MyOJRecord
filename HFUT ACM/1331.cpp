#include <iostream>
#include <sstream>

using namespace std;

int getDigit(long long num)
{
    int digit = 0;
    while (num != 0) {
        num /= 10;
        digit ++;
    }

    return digit;
}

bool isHuiWenShu(string numstr)
{
    for (int i = 0, j = numstr.length()-1; i <= numstr.length()-1; i++, j--)
    {
        if (numstr[i] != numstr[j]) return false;
    }

    return true;
}

long long getDaoNum(string str)
{
    long long num = 0;
    for (int i = str.length()-1; i >= 0; i--) {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

string getDaoNumStr(string str)
{
    string daostr = "";

    for (int i = str.length()-1; i >= 0; i--) {
        daostr += str[i];
    }

    return daostr;
}

//一个数和它的倒置数相加
string bigNumPlus(string str)
{
    string daostr = getDaoNumStr(str);
    string result = "";

    int jinwei = 0;
    for (int i = str.length()-1; i >= 0; i--) {
        int res = daostr[i] - '0' + str[i] - '0' + jinwei;
        jinwei = 0;

        if (res >= 10) {
            jinwei = 1;
            res -= 10;
        }

        char bit = res + '0';
        result = bit + result;
    }

    if (jinwei) {
        result = "1" + result;
    }

    return result;
}

int main()
{
    long long num;

    while (cin >> num) {
        stringstream ss;
        ss << num;
        string numstr;
        ss >> numstr;

        //cout << numstr;
        string show = numstr;

        long long current_num = num;

        while (!isHuiWenShu(numstr)) {
            /*
            current_num = current_num + getDaoNum(numstr);

            stringstream sss;
            sss << current_num;
            sss >> numstr;
            */
            numstr = bigNumPlus(numstr);
            show = show + "--->" + numstr;
        }

        cout << show << endl;
    }
}
