#include <iostream>
#include <string>

using namespace std;

string eightToTwo(char a) {
	switch (a) {
		case '0':
			return "000";
			break;
		case '1':
			return "001";
			break;
		case '2':
			return "010";
			break;
		case '3':
			return "011";
			break;
		case '4':
			return "100";
			break;
		case '5':
			return "101";
			break;
		case '6':
			return "110";
			break;
		case '7':
			return "111";
			break;
	}
}

char twoto16(string s) {
	char as[] = {'A', 'B', 'C', 'D', 'E', 'F'};
	
	int value = 0;
	for (int i = 0; i < s.length(); i++) {
		value = (value << 1) + (s[i] - '0');
	}
	
	if (value >= 0 && value <= 9) {
		return '0' + value;
	} else {
		return as[value-10];
	}
}

int main()
{
	int n;
	cin >> n;
	
	while (n--) {
		string num8;
		cin >> num8;
		
		string num2 = "";
		
		for (int i = 0; i < num8.length(); i++) {
			num2 += eightToTwo(num8[i]);
		}
		for (int i = 0; i < num2.length(); i++) {
			if (num2[i] == '1') {
				num2 = num2.substr(i, string::npos);
				break;
			}
		}
		
		int a = 4 - (num2.length() % 4);
		if (a != 4) {
			string zeros = "";
			for (int i = 0; i < a; i++) {
				zeros += "0";
			}
			num2 = zeros + num2;
		}
		
		string num16 = "";
		int times = num2.length() / 4;
		for (int i = 0; i < times; i++) {
			string aaa(num2, num2.length()-4, string::npos);
			num16 = twoto16(aaa) + num16;
			num2.resize(num2.length()-4);
		}
		
		cout << num16 << endl;
	}
}
