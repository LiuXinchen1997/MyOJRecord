#include <iostream>

using namespace std;

int main()
{	
	while (true) {
		int m1,m2,m3,n1,n2,n3;
		cin >> m1 >> n1;
		
		if ((m1 == 0) && (n1 == 0)) {
			break;
		}
		
		int A[m1][n1];
		for (int i = 0; i < m1; i++) {
			for (int j = 0; j < n1; j++) {
				cin >> A[i][j];
			}
		}
		
		cin >> m2 >> n2;
		int B[m2][n2];
		for (int i = 0; i < m2; i++) {
			for (int j = 0; j < n2; j++) {
				cin >> B[i][j];
			}
		}
		
		cin >> m3 >> n3;
		int C[m3][n3];
		for (int i = 0; i < m3; i++) {
			for (int j = 0; j < n3; j++) {
				cin >> C[i][j];
			}
		}
		
		bool flag = true;
		if (n1 != m2) {
			cout << "No" << endl;
		} else if ((m3 != m1) || (n3 != n2)) {
			cout << "No" << endl;
		} else {
			for (int i = 0; i < m3; i++) {
				for (int j = 0; j < n3; j++) {
					int c = 0;
					for (int k = 0; k < n1; k++) {
						c += A[i][k] * B[k][j];
					}	
					if (c != C[i][j]) {
						flag = false;
						goto L;
					}
				}
			}
			L:
				if (flag) {
					cout << "Yes" << endl;
				} else {
					cout << "No" << endl;
				}
		}	
	}	
}
