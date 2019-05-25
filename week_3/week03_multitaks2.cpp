#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

struct task {
	int id;
	int hitTIme;
	int runningTime;
	int priority;

	task(int id, int h, int r, int p) :id(id), hitTIme(h), runningTime(r), priority(p) {}
	task() {}
	task(const task& t) {
		this->id = t.id;
		this->hitTIme = t.hitTIme;
		this->runningTime = t.runningTime;
		this->priority = t.priority;
	}
};

bool cmp(const task& t1, const task& t2) {
	if (t1.priority == t2.priority)
		return t1.id < t2.id;
	return t1.priority < t2.priority;
}

long long curTime, wTime, rTime;
deque<task> works;

inline void cal() {
	task t = works.front();
	works.pop_front();
	if (curTime == 0) {
		curTime += t.runningTime + t.hitTIme;
		rTime += t.runningTime;
	}
	else {
		if (t.hitTIme < curTime) {
			wTime += (curTime - t.hitTIme);
			curTime += t.runningTime;
			rTime += (curTime - t.hitTIme);
		}
		else {
			curTime = t.hitTIme + t.runningTime;
			rTime += t.runningTime;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	long long t, n, m;
	cin >> t;
	while (t--) {
		curTime = 0;
		wTime = 0;
		rTime = 0;
		works.clear();
		string id;
		long long a, b, c;
		cin >> n >> m;
		int cnt = n + m;
		while (cnt--) {
			cin >> id >> a >> b >> c;
			if (!works.empty() && (curTime < a)) {
				sort(works.begin(), works.end(), cmp);
				while (curTime < a && !works.empty())
					cal();
			}
			if (id[0] == 'N') {
				for (int i = 0; i < works.size(); i++) {
					if (works[i].id == b) {
						works[i].priority = c;
						sort(works.begin(), works.end(), cmp);
						break;
					}
				}
			}
			else {
				int i = atoi(id.c_str());
				task t(i, a, b, c);
				works.push_back(t);
			}
			if (!works.empty() && curTime==0) {
				sort(works.begin(), works.end(), cmp);
				while (curTime <= a && !works.empty())
					cal();
			}
			
		}
		sort(works.begin(), works.end(), cmp);
		while (!works.empty())
			cal();

		cout << wTime / n << " " << rTime / n << "\n";
	}

	return 0;
}