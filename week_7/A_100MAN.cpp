#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int arr[1300] = {};

inline int hashing(int key) {
	return key % 1013;
}

inline int doubleHash(int key) {
	return 37 - (key % 37);
}

int main() {
	ios_base::sync_with_stdio(false);
	int t, n, m, k;
	cin >> t;
	string waste;
	while (t--) {
		bool flag = false;
		memset(arr, -1, sizeof(arr));
		cin >> n >> m;
		int cost = 0;
		while (n--) {
			cin >> k;
			cost = 0;
			int d = doubleHash(k);
			k = hashing(k);
			if (k == m) {
				flag = true;
				break;
			}
			while (arr[k] != -1) {
				cost += 10000;
				k = hashing(k + d);
				if (k == m) {
					flag = true;
					break;
				}
			}
			if (flag)
				break;
			arr[k] = 1;
		}
		if (flag)
			cout << 1000000 - cost << "\n";
		else
			cout << "N\n";
		
		getline(cin, waste);
	}
	
	return 0;
}