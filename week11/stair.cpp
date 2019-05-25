#include <iostream>
#define ull unsigned long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	ull t, x, y;
	cin >> t;
	while (t--) {
		ull dp[61] = {};
		dp[0] = dp[1] = 1;
		cin >> x >> y;

		for (int i = 2; i <= x; i++) {
			for (int k = 1; k <= y; k++) {
				if (i - k < 0) {
					break;
				}
				dp[i] += dp[i - k];
			}
		}
		
		cout << dp[x] << "\n";
	}

	return 0;
}