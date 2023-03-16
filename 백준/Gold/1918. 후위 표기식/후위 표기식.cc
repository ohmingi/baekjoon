#include <iostream>
#include <string>

using namespace std;

class Node {
private:
	Node* next;
	char value;
public:
	friend class Stack;
};


class Stack {
private:
	int datasize;
	Node* Top;

public:
	Stack()
	{
		datasize = 0;
		Top = nullptr;
	}

	void push(char x) {
		Node* node = new Node;
		node->value = x;
		node->next = Top;
		Top = node;
		datasize++;
	}

	char top() {
		if (empty()) return -1;
		return  Top->value;
	}

	char pop() {
		if (empty()) {
			return -1;
		}
		Node* node = Top;
		Top = Top->next;
		int tmp = node->value;
		delete node;
		datasize--;
		return tmp;
	}
	bool empty() {
		return datasize == 0;
	}

	int size() {
		return datasize;
	}
};

int check(char c) {
	if (c == '*' || c == '/') {
		return 3;
	}

	else if (c == '+' || c == '-') {
		return 2;
	}

	else {
		return 1;
	}
}

int main() {
	string str;
	cin >> str;

	Stack stack;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			cout << str[i];
		}

		else {
			if (str[i] == '(') {
				stack.push(str[i]);
			}

			else if (str[i] == ')') {
				while (!stack.empty() && stack.top() != '(') {
					cout << stack.top();
					stack.pop();
				}

				stack.pop();
			}

			else {
				while (!stack.empty() && (check(stack.top()) >= check(str[i]))) {
					cout << stack.top();
					stack.pop();
				}

				stack.push(str[i]);
			}
		}
	}

	while (!stack.empty()) {
		cout << stack.top();
		stack.pop();
	}
}

