#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;


int main()
{
	int t;
	cin >> t;
	cin.get();
	stack<string> op;
	while (t--) {
		string str;
		getline(cin, str);
		string c;
		stringstream ss(str);
		string result = "";
		bool flag = false;

		while (ss >> c) {
			if (c[0] == '$')
				break;
			if (c[0] == '+' || c[0] == '-')
			{
				while (!op.empty() && op.top() != "(")
				{
					string ch = op.top();
					result += ch + " ";
					op.pop();
				}
				op.push(c);
			}
			else if (c[0] == '(')
				op.push(c);
			else if (c[0] == ')') {
				while (!op.empty() && op.top() != "(") {
					string ch = op.top();
					result += ch + " ";
					op.pop();
				}
				op.pop();

			}
			else {
				result += c + " ";
			}
		}

		while (!op.empty())
		{
			string ch(op.top());
			result += ch + " ";
			op.pop();
		}

		stringstream ss2(result);
		stack<int> num;
		while (ss2 >> c) {
			if (c[0] == '+' || c[0] == '-') {
				if (num.empty()) {
					flag = true;
					break;
				}
				long long n1 = num.top();
				num.pop();
				if (num.empty()) {
					flag = true;
					break;
				}
				long long n2 = num.top();
				num.pop();
				char o = c[0];
				int res = 0;
				switch (o) {
				case '+':
					res = n1 + n2;
					break;
				case '-':
					res = n2 - n1;
					break;
				}
				num.push(res);
			}
			else if (c[0] == '(' || c[0] == ')') {
				flag = true;
				break;
			}
			else {
				num.push(atoi(c.c_str()));
			}
		}

		if (flag)
			cout << "N\n";
		else
			cout << num.top() << "\n";
	}


	return 0;
}