#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

bool flag = true;
long long a=-100000000000, b= -100000000000, ret;

void cal(stack<string>& opst) {
	string s;
	while (!opst.empty()&&opst.size() != 1) {
		if (opst.top() == "+" || opst.top() == "-" || opst.top() == "(") {
			flag = false;
			return;
		}
		a = atoll(opst.top().c_str()); opst.pop();
		if (opst.top() != "+" && opst.top() != "-" ) {
			flag = false;
			return;
		}
		s = opst.top(); opst.pop();	
		if (opst.top() == "+" || opst.top() == "-" || opst.top() == "(") {
			flag = false;
			return;
		}
		b = atoll(opst.top().c_str()); opst.pop();

		if (a <=0 || b <=0)
			flag = false;

		if (s == "-") {
			ret = a - b;
		}
		else if (s == "+")
			ret = a + b;

		char buffer[10000];
		sprintf_s(buffer, "%lld", ret);
		opst.push(string(buffer));
	}
	if (opst.empty()) {
		flag = false;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	cin.get();
	while (t--) {
		a = -100000000000; b = -100000000000;
		flag = true;
		string str;
		getline(cin, str);
		stringstream ss(str);
		string o;
		stack<string> st;
		stack<string> opst;
		while (ss >> o) {
			if (o == "$") {
				break;
			}
			else if (o != ")")
				st.push(o);
			else {
				while (true) {
					if (st.empty()) {
						flag = false;
						break;
					}
					if (st.top() != "(") {
						opst.push(st.top());
						st.pop();
					}
					else {
						st.pop();
						break;
					}
				}
				cal(opst);
				if (!flag)
					break;
				st.push(opst.top());
				opst.pop();
				
			}
		}
		if (flag) {
			while (!st.empty()) {
				opst.push(st.top());
				st.pop();
			}
			cal(opst);
			while (!opst.empty()) {
				st.push(opst.top());
				opst.pop();
			}
			if (st.size() == 1 && flag)
				cout << st.top() << "\n";
			else
				cout << "N\n";
		}
		else {
			cout << "N\n";
		}
	}

	return 0;
}