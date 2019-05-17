#include <iostream>

#define mod  1000000007
using namespace std;

long long arr[4001][4001] = {};

long long cal(long long n, long long k) {
	if (n == k || k == 0 || n == 1) {
		arr[n][k] = 1;
		return arr[n][k];
	}
	else {
		if (arr[n - 1][k] == 0)
			arr[n - 1][k] == cal(n - 1, k) % mod;
		if (arr[n - 1][k - 1] == 0)
			arr[n - 1][k - 1] == cal(n - 1, k - 1) % mod;
		return arr[n][k] = (arr[n - 1][k] + arr[n - 1][k - 1]) % mod;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	long long t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cout << cal(n, k) << "\n";
	}
	return 0;
}