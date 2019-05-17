#include <iostream>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>

#define myP pair<pair<pair<int, int>, pair<int, int> >, int>

using namespace std;

bool cmp(myP p1, myP p2) {
	if (p1.second == p2.second) {
		if (p1.first.first.second + p1.first.second.second == p2.first.first.second + p2.first.second.second)
			return p1.first.first.first + p1.first.second.first < p2.first.first.first + p2.first.second.first;
		return p1.first.first.second + p1.first.second.second < p2.first.first.second + p2.first.second.second;
	}
	return p1.second < p2.second;
}


int main() {
	int t, n, m;
	char c;
	int x, y;
	cin >> t;
	while (t--) {
		map<char, vector<pair<int, int> > > card;
		map<char, deque<myP> >dist;
		map<char, set<pair<int, int> > > com;
		set<char> al;
		cin >> n >> m;
		while (m--) {
			cin >> c >> x >> y;
			for (int i = 0; i < card[c].size();i++) {
				int d = (card[c][i].first - x)*(card[c][i].first - x) + (card[c][i].second - y)*(card[c][i].second - y);
				if (card[c][i].second <= y) {
					if (card[c][i].first <= x)
						dist[c].push_back({ {card[c][i],{x,y}},d });
					else
						dist[c].push_back({ {{x,y},card[c][i]},d });
				}
				else {
						dist[c].push_back({ {{x,y},card[c][i]},d });
				}
				if (al.find(c) == al.end()) {
					al.insert(c);
				}
			}
			card[c].push_back({ x,y });
		}
		int cnt = 0;
		while (cnt<al.size()) {
			for (set<char>::iterator it = al.begin(); it != al.end();it++) {
				sort(dist[*it].begin(), dist[*it].end(), cmp);
				while (!dist[*it].empty()) {
					pair<pair<pair<int, int>, pair<int, int> >, int> p = dist[*it].front();
					dist[*it].pop_front();
					if (com[*it].find(p.first.first) == com[*it].end()&&com[*it].find(p.first.second)==com[*it].end()) {
						cout << *it << " " << p.first.first.first << " " << p.first.first.second <<
							" " << p.first.second.first << " " << p.first.second.second << "\n";
						com[*it].insert(p.first.first);
						com[*it].insert(p.first.second);
					}
				}
			}
			cnt++;
		}
	}

	return 0;
}