#include<iostream>
using namespace std;

#define FOR(x,y) for(int i = (x); i<(y); i++)
#define ll long long
#define DIV 1000000007

int N;
int K;

ll fact[4000002];
ll inv[4000002];
ll result;

// 분할 정복으로 구하는 제곱 수. 제곱수를 2진수로 생각해서, 2의 지수승 합으로 나타낼 수 있음을 응용한다.
ll power(ll value, ll index) {
	ll result = 1;

	while (index > 0)
	{
		if (index % 2 == 1) {
			result *= value;
			result %= DIV;
		}

		value *= value;
		value %= DIV;
		index /= 2;
	}

	return result;
}

ll f(int n) {
	for (int i = 0; i <= n; i++) {
		if (i >= 1)
			fact[i] = i * fact[i - 1] % DIV;
		else
			fact[i] = 1;
	}

	return n;
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	f(4000);
	// 페르마의 소정리를 이용해서, a^(p-2)할 a를 설정해야하는데, 일단 그냥 N!으로 설정했습니다.
	inv[4000] = power(fact[4000], DIV - 2);

	// N!에 관한 역원값을 만들어 줬으니, (N-K)!을 위해, (N-1)!, (N-2)!을 미리 계산해준다.
	for (int i = 3999; i > 0; i--) {
		inv[i] = (inv[i + 1] * (i + 1)) % DIV;
	}

	cin >> t;
	while (t--) {
		result = 0;
		cin >> N >> K;
		if (N == K || K == 0) {
			cout << "1";
			return 0;
		}

		// N!/(K!(N-K)!) % DIV를 구해줍니다.
		// 주의해야할 점은 result *= value % DIV를 하면 안되고, 밑의 식처럼 풀어줘야 한다는 것입니다.
		result += fact[N];
		result = (result * inv[K]) % DIV;
		result = (result * inv[N - K]) % DIV;

		cout << result << "\n";
	}
	return 0;
}
