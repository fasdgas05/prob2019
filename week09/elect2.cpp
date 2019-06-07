#include <iostream>

#define mod 1000000007 

using namespace std;

typedef long long ll;

ll fact(ll n) {
	ll res = 1;
	for (ll i = 2; i <= n; i++) {
		res *= i;
		res %= mod;
	}
	return res;
}

ll mul(ll n) {
	ll p = mod - 2;
	ll res = 1;
	while (p > 0) {
		if (p % 2 == 1) {
			res *= n;
			res %= mod;
		}
		n *= n;
		n %= mod;
		p /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	int t, n, r;
	cin >> t;
	while (t--) {
		cin >> n >> r;
		
		ll dividant = fact(n);
		ll divisor;
		divisor = fact(r);
		divisor *= fact(n - r);
		divisor %= mod;

		divisor = mul(divisor);
		dividant = dividant * divisor;
		dividant %= mod;

		cout << dividant << "\n";
	}
}