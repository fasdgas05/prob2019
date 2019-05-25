#include <iostream>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int t, b, l, n;
	cin >> t;
	int map[401][401] = {};

	while (t--) {
		cin >> b >> l >> n;
		b *= 7;
		int tmp = 1;
		for (int i = 1; i <= l-1; i++) {
			b -= (i*(i + 1) / 2);
			tmp *= 3;
		}
		if (b <= 0) {
			cout << "0\n";
			continue;
		}
		


		memset(map, 0, sizeof(map));
			for (int i = 1; i <= l; i++) {
				for (int j = 1; j <= i; j++) {
					if (i != l && j != i&&j < i&&j>1) {
						map[i][j] += 3*b;
					}
					else if (i == 1 && j == 1 || i == l&&j == 1
						|| i == l&&j == l) {
						map[i][j] += 1*b;
					}
					else {
						map[i][j] += 2*b;
					}
				}
			}
		
		int res;
		int x=1, y=1;
		for (int i = 1; i <= n; i++) {
			if (x == y) {
				x++; y = 1;
			}
			else {
				y++;
			}
		}
		res = map[x][y];
		if (res == 0)
			cout << "0\n";
		else if (res >= tmp)
			cout << "1\n";
		else
			cout << "2\n";

	}

	return 0;
}