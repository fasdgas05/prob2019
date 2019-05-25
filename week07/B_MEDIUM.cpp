#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int t, n, m;

	cin >> t;
	while (t--) {
		priority_queue<int, deque<int>, greater<int> > min_heap;
		priority_queue<int, deque<int> > max_heap;
		cin >> n;
		while (n--) {
			cin >> m;
			if (min_heap.empty() && max_heap.empty()) {
				max_heap.push(m);
			}
			else if (min_heap.size() == max_heap.size()) {
				if (min_heap.top() < m) {
					min_heap.push(m);
					max_heap.push(min_heap.top());
					min_heap.pop();
				}
				else {
					max_heap.push(m);
				}
			}
			else {
				if (max_heap.top() > m) {
					max_heap.push(m);
					min_heap.push(max_heap.top());
					max_heap.pop();
				}
				else {
					min_heap.push(m);
				}
			}
			cout << max_heap.top() << " ";
		}
		cout << "\n";
	}
	
	return 0;
}