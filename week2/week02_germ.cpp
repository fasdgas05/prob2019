#include <iostream>
#include <queue>
 
using namespace std;

int map[100][100] = {};
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {
	ios_base::sync_with_stdio(false);
	int t, n, m, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int l = 0; l < n; l++) {
				cin >> map[i][l];
				map[i][l] *= -1;
			}
		}
		queue<pair<int, int> > germ;
		while (m--) {
			cin >> b >> a;
			a = n - a - 1;
			map[a][b] = 1;
			germ.push({ a,b });
		}
		int sec = 0;
		while (!germ.empty()) {
			pair<int, int> p = germ.front();
			germ.pop();
			int i = p.first;
			int l = p.second;
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k];
				int y = l + dy[k];
				if (x >= 0 && x < n&&y >= 0 && y < n) {
					if (map[x][y] == -1 || map[x][y] != 0)
						continue;
					else {
						map[x][y] = map[i][l] + 1;
						germ.push({ x,y });
						if (sec < map[x][y])
							sec = map[x][y];
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int l = 0; l < n; l++) {
				if (map[i][l] == 0) {
					sec = 0;
					break;
				}
			}
		}

		cout << sec - 1 << "\n";
	}

	return 0;
}