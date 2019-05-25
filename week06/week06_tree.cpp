#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int no[10001] = {};

int main() {
	ios_base::sync_with_stdio(false);

	int t, n, k;
	cin >> t;

	while (t--) {
		memset(no, -1, sizeof(no));
		cin >> n >> k;
		int par, chi;
		n--;
		while (n--) {
			cin >> par >> chi;
			no[chi] = par;
		}

		vector<int> sk1,sk2;
		int a, b;
		while (k--) {
			sk1.clear();
			sk2.clear();
			cin >> a >> b;
			sk1.push_back(a);
			sk2.push_back(b);

			while (no[a] != -1) {
				a = no[a];
				sk1.push_back(a);
			}
			while (no[b] != -1) {
				b = no[b];
				sk2.push_back(b);
			}
			int res = 0;
			bool flag = false;
			for (int i = 0; i < sk1.size(); i++) {
				for (int l = 0; l < sk2.size(); l++) {
					if (sk1[i] == sk2[l]) {
						res = sk1[i];
						flag = true;
						break;
					}
					if (flag)
						break;
				}
			}

			cout << res << " ";
		}
		cout << "\n";


	}

	return 0;
}