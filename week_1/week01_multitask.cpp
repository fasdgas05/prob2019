#include <iostream>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	long long t, n, w, r, ctime, rtime, wtime;
	cin >> t;
	while (t--) {
		ctime = 0;
		rtime = 0;
		wtime = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> w >> r;

			if (ctime == 0) {
				rtime = r;
				ctime = r+w;
			}
			else {
				if (ctime < w) {
					ctime = r + w;
					rtime += r;
				}
				else {
					wtime += ctime - w;
					ctime += r;
					rtime += ctime - w;
				}
			}
		}

		cout << wtime / n << " " << rtime / n << "\n";
	}
	return 0;
}