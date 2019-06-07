#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

float remain;
int inner_bound, next_bound, nxt, cnt;

int main() {
	ios_base::sync_with_stdio(false);
	int t, b, l, n;
	cin >> t;
	while (t--) {
		cin >> b >> l >> n;
		vector<float> upper, lower;

		upper.push_back(b * 7);
		for (int i = 1; i <= l; i++) {
			lower.clear();
			lower.resize((i + 1) * (i + 2) / 2, 0.0f);
			inner_bound = i * (i + 1) / 2;
			next_bound = inner_bound + i + 1;
			nxt = 1, cnt = 0;
			for (int k = 0; k < upper.size(); k++) {
				if (upper[k] > 1.0f) {
					remain = (upper[k] - 1.0f) / 3.0f;
					if (k <= next_bound)
						lower[k] += remain;
					if (k + nxt <= next_bound)
						lower[k + nxt] += remain;
					if (k + nxt + 1 <= next_bound)
						lower[k + nxt + 1] += remain;
				}
				cnt++;
				if (nxt == cnt) {
					nxt++;
					cnt = 0;
				}
			}
			if (i != l)
				swap(upper, lower);

		}
		if (upper[n - 1] >= 1.0f)
			cout << 1 << "\n";
		else if (upper[n - 1] == 0.0f)
			cout << 0 << "\n";
		else
			cout << 2 << "\n";
	}

	return 0;
}