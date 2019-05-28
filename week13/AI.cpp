#include <iostream>
#include <cstring>

using namespace std;

bool map[51][51] = {};
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int l, b, v;

void dfs(int x, int y) {
	map[x][y] = false;
	for (int i = 0; i < 4; i++) {
		int nxt_x = x + dx[i];
		int nxt_y = y + dy[i];
		if (nxt_x >= 0 && nxt_x < l&&nxt_y >= 0 && nxt_y < b)
			if (map[nxt_x][nxt_y])
				dfs(nxt_x, nxt_y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		memset(map, false, sizeof(map));
		cin >> l >> b >> v;
		int x, y;
		while (v--) {
			cin >> x >> y;
			map[x][y] = true;
		}
		int res = 0;
		
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < b; j++) {
				if (map[i][j]) {
					res++;
					dfs(i, j);
				}
			}
		}

		cout << res << "\n";
	}
	return 0;
}