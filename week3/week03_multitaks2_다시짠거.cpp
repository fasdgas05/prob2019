#include <iostream>
#include <deque>
#include <string>
#include <cstdlib>
#include <algorithm>

#define ll long long
#define max(a,b) a>b?a:b

using namespace std;

struct task {
	int id;
	ll hit_time;
	ll run_time;
	int priority;

	task(const string& id = NULL, ll h = -1, ll r = -1, int p = -1)
		:id(atoi(id.c_str())), hit_time(h), run_time(r), priority(p) {}

};

bool cmp(const task& t1, const task& t2) {
	if (t1.priority == t2.priority)
		return t1.id < t2.id;
	return t1.priority < t2.priority;
}
deque<task> d;
ll run_time, hit_time, cur_time;

inline void cal() {
	task t = d.front();
	d.pop_front();
	if (cur_time == 0) {
		cur_time += t.run_time + t.hit_time;
		run_time += t.run_time;
	}
	else {
		if (t.hit_time < cur_time) {
			hit_time += (cur_time - t.hit_time);
			cur_time += t.run_time;
			run_time += (cur_time - t.hit_time);
		}
		else {
			cur_time = t.hit_time + t.run_time;
			run_time += t.run_time;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	ll t, n, m, ht, rt;
	int p;
	string id;
	cin >> t;
	while (t--) {
		cur_time = 0;
		hit_time = 0;
		run_time = 0;
		d.clear();
		cin >> n >> m;
		int cnt = n + m;
		while (cnt--) {
			cin >> id >> ht >> rt >> p;
			if (!d.empty() && ht > cur_time) {
				sort(d.begin(), d.end(), cmp);
				while (!d.empty()&&ht > cur_time) {
					cal();
				}
			}
			if (id[0] == 'N') {
				for (int i = 0; i < d.size(); i++) {
					if (d[i].id == rt) {
						d[i].priority = p;
						break;
					}
				}
			}
			else {
				d.push_back(task(id, ht, rt, p));
				if (ht == 0) {
					cal();
				}
			}
		}
		sort(d.begin(), d.end(), cmp);
		while (!d.empty()) {
			cal();
		}

		cout << hit_time / n << " " << run_time / n << "\n";
	}

	return 0;
}