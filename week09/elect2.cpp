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

// ���� �������� ���ϴ� ���� ��. �������� 2������ �����ؼ�, 2�� ������ ������ ��Ÿ�� �� ������ �����Ѵ�.
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
	// �丣���� �������� �̿��ؼ�, a^(p-2)�� a�� �����ؾ��ϴµ�, �ϴ� �׳� N!���� �����߽��ϴ�.
	inv[4000] = power(fact[4000], DIV - 2);

	// N!�� ���� �������� ����� ������, (N-K)!�� ����, (N-1)!, (N-2)!�� �̸� ������ش�.
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

		// N!/(K!(N-K)!) % DIV�� �����ݴϴ�.
		// �����ؾ��� ���� result *= value % DIV�� �ϸ� �ȵǰ�, ���� ��ó�� Ǯ����� �Ѵٴ� ���Դϴ�.
		result += fact[N];
		result = (result * inv[K]) % DIV;
		result = (result * inv[N - K]) % DIV;

		cout << result << "\n";
	}
	return 0;
}
