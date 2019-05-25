#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

#define y first 
#define x second

struct cardPair {
	pair<int, int> c1;
	pair<int, int> c2;
	int dist;

	cardPair(pair<int, int> p1, pair<int, int> p2) {
		dist = (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
		if (p1.y < p2.y) {
			c1 = p1;
			c2 = p2;
		}
		else if(p1.y==p2.y){
			if (p1.x < p2.x) {
				c1 = p1;
				c2 = p2;
			}
			else {
				c1 = p2;
				c2 = p1;
			}
		}
		else {
			c1 = p2;
			c2 = p1;
		}
	}
};

bool cmp(const cardPair& cp1, const cardPair& cp2) {
	if (cp1.dist == cp2.dist) {
		if (cp1.c1.y + cp1.c2.y == cp2.c1.y + cp2.c2.y)
			return cp1.c1.x + cp1.c2.x < cp2.c1.x + cp2.c2.x;
		return cp1.c1.y + cp1.c2.y < cp2.c1.y + cp2.c2.y;
	}
	return cp1.dist < cp2.dist;
}


map<char, set<pair<int, int> > > ms;
map<char, deque<cardPair> > mv;
set<pair<int, int> > cs;
priority_queue<char, vector<char>, greater<char> > al;


int main() {
	ios_base::sync_with_stdio(false);
	int t, n, m, a, b;
	char c;
	cin >> t;
	while (t--) {
		mv.clear();
		ms.clear();
		cs.clear();
		cin >> n >> m;
		while (m--) {
			cin >> c >> a >> b;
			for (set<pair<int, int> >::iterator iter = ms[c].begin(); iter != ms[c].end(); iter++) {
				mv[c].push_back(cardPair({ b, a }, { (*iter).y, (*iter).x }));
			}
			ms[c].insert({ b,a });
			al.push(c);
		}

		while(!al.empty()) {
			char i = al.top();
			al.pop();
			if (mv[i].empty())
				continue;
			sort(mv[i].begin(), mv[i].end(), cmp);
			while(!mv[i].empty()) {
				cardPair cp = mv[i].front();
				mv[i].pop_front();
				if (cs.find(cp.c1) == cs.end() && cs.find(cp.c2) == cs.end()) {
					cout << i << " " << cp.c1.x << " " << cp.c1.y << " " << cp.c2.x << " " << cp.c2.y << "\n";
					cs.insert(cp.c1);
					cs.insert(cp.c2);
				}
			}
		}
	}

	return 0;
}
