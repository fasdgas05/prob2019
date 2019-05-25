#include <vector>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int t, n, h;
	cin >> t;
	while (t--) {
		vector<int> b, r;
		cin >> n;
		b.push_back(0);
		while (n--) {
			cin >> h;
			b.push_back(h);
			for (int i = b.size() - 2; i >= 0; i--) {
				if (b[i] >= h) {
					r.push_back(i);
					break;
				}
				else if (i == 0) {
					r.push_back(0);
					break;
				}
			}
		}
		for (int i = 0; i < r.size(); i++) {
			cout << r[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}