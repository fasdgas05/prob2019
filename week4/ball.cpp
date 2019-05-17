#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int t, l, m, n, k;
	vector<int> arr;
	cin >> t;
	while (t--) {
		arr.clear();
		cin >> n >> l >> m;
		while (n--) {
			cin >> k;
			if (k < 0)
				arr.push_back(-k);
			else
				arr.push_back(l - k);
		}
		sort(arr.begin(), arr.end());

		cout << arr[m - 1] << "\n";
	}

	return 0;
}