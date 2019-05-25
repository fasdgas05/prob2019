#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int t, n, h;
	vector<int> ret;
	cin >> t;
	while (t--) {
		stack<pair<int, int> > s1;
		int sz = 0;
		cin >> n;
		ret.clear();
		ret.resize(n);
		while(n--) {
			cin >> h;
			if (s1.empty()) {
				s1.push({ sz++,h });
			}
			else {
				if (h <= s1.top().second) {
					ret[sz] = s1.top().first + 1;
					s1.push({ sz++,h });
				}
				else {
					while (!s1.empty()&&s1.top().second < h) {
						s1.pop();
					}
					if (!s1.empty()) {
						ret[sz] = s1.top().first + 1;
						s1.push({ sz++,h });
					}
					else {
						ret[sz] = 0;
						s1.push({ sz++,h });
					}
				}
			}
		}
		for (int i = 0; i < ret.size(); i++)
			cout << ret[i] << " ";
		cout << "\n";
	}

	return 0;
}