#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int t, n, m, k, w1 = 0, w2 = 0;
	cin >> t;
	while (t--) {
		int indegre[10001] = {};
		cin >> n >> m;
		vector<int> g[10001];
		while (m--) {
			cin >> k;
			w1 = 0;
			w2 = 0;
			while (k--) {
				cin >> w2;
				if (w1 != 0) {
					g[w1].push_back(w2);
					indegre[w2]++;
				}
				w1 = w2;
			}
		}
		vector<int> res;
		priority_queue<int, vector<int>, greater<int> > q;
		for (int i = 1; i <= n; i++) {
			if (indegre[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			int cur = q.top();
			res.push_back(cur);
			q.pop();
			for (int i = 0; i < g[cur].size(); i++) {
				int nxt = g[cur][i];
				indegre[nxt]--;
				if (indegre[nxt] == 0) {
					q.push(nxt);
				}
			}
		}

		if (res.size() == n)
			for (int i = 0; i<res.size(); i++)
				cout << res[i] << " ";
		else
			cout << "-1";
		cout << "\n";
	}
	return 0;
}