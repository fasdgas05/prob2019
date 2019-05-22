#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int dp[100001] = {};
const int init_val = 100001;

int main() {
	ios_base::sync_with_stdio(false);
	int t, n, m, k;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		fill_n(dp, n + 1, init_val);
		while (m--) {
			cin >> k;
			dp[k] = 1;
			for (int i = k; i <= n; i++) {
				dp[i] = min(dp[i], dp[i - k] + 1);
			}
		}
		if (dp[n] == init_val)
			dp[n] = 0;
		cout << dp[n] << "\n";
	}
	return 0;
}