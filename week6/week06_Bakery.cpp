#include <iostream>
#include <vector>
#include <cstring>
#include <cstdint>
using namespace std;

vector<unsigned long long> cou;
uint64_t g ingre[101][101] = {};

void dfs(int n,vector<int>* tree,unsigned long long count) {
	for (int i = 0; i < tree[n].size(); i++) {
		if (tree[tree[n][i]].empty()) {
			cou[tree[n][i]] += count*ingre[n][tree[n][i]];
		}
		else {
			dfs(tree[n][i], tree, count*ingre[n][tree[n][i]]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int t, n, m;
	unsigned long long x, y, k;
	cin >> t;
	while (t--) {
		cin >> n;
		cou.clear();
		cou.resize(n + 1);
		memset(ingre, 0, sizeof(ingre));
		vector<int> tree[101];
		cin >> m;
		while (m--) {
			cin >> x >> y >> k;
			tree[x].push_back(y);
			ingre[x][y] = k;
		}

		dfs(n, tree, 1);

		for (int i = 1; i <= n; i++) {
			if (tree[i].empty()&&cou[i]!=0)
				cout << i << " " << cou[i] << "\n";
		}

	}

	return 0;
}