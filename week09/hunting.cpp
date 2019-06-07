#include <iostream>
#include <cstring>
using namespace std;

long long t, n, k;
int height[1001] = {};
int d[1001][1001] = {};

void dfs(int num) {
	cout << num << "\n";
	while (true) {
		int min_h = 1000000001;
		int min_idx = -1;
		height[num] = -1;
		for (int i = 0; i < n; i++) {
			if (height[i] != -1 && height[i] < min_h&&d[num][i] == 1) {
				min_h = height[i];
				min_idx = i;
			}
		}
		if (min_idx == -1) {
			return;
		}
		dfs(min_idx);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		memset(height, -1, sizeof(height));
		memset(d, -1, sizeof(d));
		int min_h = 1000000001;
		int min_idx;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> height[i];
			if (min_h > height[i]) {
				min_h = height[i];
				min_idx = i;
			}
		}

		int x, y;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			d[x][y] = 1;
			d[y][x] = 1;
		}
		while (true) {
			dfs(min_idx);
			min_h = 1000000001;
			min_idx = -1;
			for (int i = 0; i < n; i++) {
				if (height[i] != -1 && height[i] < min_h) {
					min_h = height[i];
					min_idx = i;
				}
			}
			if (min_idx == -1)
				break;
		}
	}
	return 0;
}