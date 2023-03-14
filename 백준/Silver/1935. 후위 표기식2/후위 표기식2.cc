#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Node {
private:
	Node* next;
	double value;
public:

	Node(double value, Node* node) {
		this->value = value;
		next = node;
	}

	double getValue();
	void setValue(double);
	Node* getNext();
	void setNext(Node*);
};

double Node::getValue() {
	return value;
}

void Node::setValue(double value) {
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
	int size = 0;
	Node* Top = nullptr;

public:

	void push(double);
	double top();
	double pop();
	bool empty();
};

void Stack::push(double value) {
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

double Stack::top() {
	return Top->getValue();
}

double Stack::pop() {
	Node* node = Top;
	Top = Top->getNext();
	double tmp = node->getValue();
	delete node;
	size--;
	return tmp;
}

bool Stack::empty() {
	return size == 0;
}


int main() {
	int n;
	cin >> n;
	string word;
	cin >> word;
	Stack stack;

	vector <int> v( n );

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i{ 0 }; i < word.length(); i++) {

		if (word[i]>='A'&& word[i]<='Z') {
			stack.push(v[word[i]-'A']);
		}

		else
		{
			if (!stack.empty())
			{
				double tmp = stack.top();
				stack.pop();

				if (word[i] == '+')
				{
					tmp = stack.top() + tmp;
				}
				else if (word[i] == '-')
				{
					tmp = stack.top() - tmp;
				}
				else if (word[i] == '*')
				{
					tmp = stack.top() * tmp;
				}
				else if (word[i] == '/')
				{
					tmp = stack.top() / tmp;
				}
				stack.pop();
				stack.push(tmp);
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << stack.top() << '\n';

	return 0;
}

