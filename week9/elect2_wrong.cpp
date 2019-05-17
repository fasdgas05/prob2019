#include <iostream>

#define mod  1000000007
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	long long t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (k > n / 2) {
			k = n - k;
		}
		unsigned long long mul = 1, temp = 1, res = 1;
		for (int i = 0; i < k; i++) {
			mul *= (n - i);
			temp *= (i + 1);
			if (mul%temp == 0) {
				res *= mul / temp;
				mul = 1;
				temp = 1;
				res %= mod;
			}
			else if (res%temp == 0) {
				res /= temp;
				res *= mul;
				temp = 1;
				mul = 1;
				res %= mod;
			}
			else if ((res*mul) % temp == 0) {
				res *= mul;
				res /= temp;
				temp = 1;
				mul = 1;
				res %= mod;
			}
		}
		res *= mul;
		res /= temp;
		temp = 1;
		mul = 1;
		res %= mod;

		cout << res << "\n";
	}
	return 0;
}