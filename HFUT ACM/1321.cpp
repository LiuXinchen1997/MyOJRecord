#include <iostream>
#include <set>

using namespace std;

int abs(int n) {
	return n >= 0? n : -n;
}

int main()
{
	int n;
	while(cin >> n) {
	set<short> s;
	for (int i = 0; i < n; i++) {
		short a; cin >> a;
		s.insert(abs(a));
	}

	cout << n - s.size() << endl;
	}
	return 0;
}
