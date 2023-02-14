#include <iostream>

using namespace std;

class Node {
private:
	Node* next;
	char value;
public:

	Node(char value, Node* node) {
		this->value = value;
			next = node;
	}

	int getValue();
	void setValue(char);
	Node* getNext();
	void setNext(Node*);
};

int Node::getValue() {
	return value;
}

void Node::setValue(char value) {
	this->value = value;
}

Node* Node::getNext() {
	return next;
}

void Node::setNext(Node* node) {
	next = node;
}

class Stack {
private:
	int size=0;
	Node* Top=nullptr;

public:

	void push(char);
	char top();
	void pop();
	bool empty();
};

void Stack::push(char value) {
	Node* node = new Node(value, nullptr);

	if (Top == nullptr) {
		Top = node;
	}

	else {
		node->setNext(Top);
		Top = node;
	}

	size++;
}

char Stack::top() {
	return Top->getValue();
}

void Stack:: pop() {
	Node* node = Top;
	Top = Top->getNext();
	delete node;
	size--;
}

bool Stack::empty() {
	return size == 0;
}

int check(char word) {

	if (word == '*' || word == '/') {
		return 3;
	}
	else if (word == '+' || word == '-') {
		return 2;
	}

	else
		return 1;
}


int main() {
	string word;
	cin >> word;
	Stack stack;

	for (int i{ 0 }; i < word.length(); i++) {

		if ('A' <= word[i] && word[i] <= 'Z') {
			cout << word[i];
		}

		else {
			if (word[i] == '(') {
				stack.push(word[i]);
			}

			else if (word[i]==')') {
				while (!stack.empty()&&stack.top()!='(') {
					cout << stack.top();
					stack.pop();
				}

				stack.pop();
			}

			else {
				while (!stack.empty() && (check(stack.top()) >= check(word[i]))) {
					cout << stack.top();
					stack.pop();
				}
				stack.push(word[i]);
			}
		}

		
	}

	while (!stack.empty()) {
		cout << stack.top();
		stack.pop();
	}
}

