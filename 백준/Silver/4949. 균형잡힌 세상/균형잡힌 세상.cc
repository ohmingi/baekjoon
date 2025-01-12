#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool check(char c) {
	if (c == '(' || c == '[') {
		return true;
	}
	else {
		return false;
	}
}

bool check1(char c) {
	if (c == ')' || c == ']') {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (true) {
		string str;

		getline(cin, str);

		if (str == ".") {
			break;
		}

		stack<char> st;
		bool b = true;

		for (int i = 0; i < str.size(); i++) {
			if (st.empty() && check1(str[i])) {
				b = false;
				break;
			}
			else if (check(str[i])) {
				st.push(str[i]);
			}
			else if (check1(str[i])) {
				if (str[i] == ')') {
					if (st.top() == '(') {
						st.pop();
					}
					else {
						b = false;
						break;
					}
				}
				else if (str[i] == ']') {
					if (st.top() == '[') {
						st.pop();
					}
					else {
						b = false;
						break;
					}
				}
			}
		}

		if (b == true && st.empty()) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
	}
}