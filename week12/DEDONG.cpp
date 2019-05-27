#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>


using namespace std;

const int init_val = 1000000001;

int result[1001] = {};

int main() {
	ios_base::sync_with_stdio(false);

	int t, n, m, h, k;

	cin >> t;
	while (t--) {
		vector<int> g[1001];
		int start = 0, min_h = init_val;
		cin >> n >> m >> k;
		fill_n(result, 1001, init_val);

		for (int i = 0; i < n; i++) {
			cin >> h;
			if (min_h > h) {
				start = i;
				min_h = h;
			}
		}

		int f, to;
		while (m--) {
			cin >> f >> to;
			g[f].push_back(to);
			g[to].push_back(f);
		}

		//dijkstra alogrithm with no weight
		result[start] = 0;
		queue<int> pq;
		pq.push(start);
		while (!pq.empty()) {
			int cur = pq.front();
			pq.pop();
			for (int i = 0; i < g[cur].size(); i++) {
				int leng = result[cur] + 1;
				int nxt = g[cur][i];
				if (result[nxt] > leng) {
					result[nxt] = leng;
					pq.push(nxt);
				}
			}
		}

		while (k--) {
			cin >> h;
			if (result[h] == init_val)
				cout << "-1\n";
			else
				cout << result[h] << "\n";
		}
	}


	return 0;
}