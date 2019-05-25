#include <iostream>
#include <algorithm>

using namespace std;

int v[1000000] = {};

int main() {
	ios_base::sync_with_stdio(false);
	long long t, n, m, leng;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		while (m--) {
			cin >> leng;
			cout << lower_bound(v, v + n, leng) - v + 1 << "\n";
		}
	}
	return 0;
}