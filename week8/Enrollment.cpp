#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	map<int, bool> stu;
	map<string, bool> name;
	int t, n, id;
	string na;
	cin >> t;
	while (t--) {
		int dup_id = 0, dup_name = 0;
		stu.clear();
		name.clear();
		cin >> n;
		while (n--) {
			cin >> id >> na;
			if (stu.find(id) != stu.end()) {
				if (!stu[id]) {
					dup_id++;
					stu[id] = true;
				}
			}
			else {
				stu[id] = false;
				if (name.find(na) != name.end()) {
					dup_name++;
					if (!name[na]) {
						dup_name++;
						name[na] = true;
					}
				}
				else {
					name[na] = false;
				}
			}
		}

		cout << dup_id << " " << dup_name << "\n";
	}
	return 0;
}