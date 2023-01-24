#include <iostream>
#include <vector>

using namespace std;

class Node {
private:
	Node* next;
	int value;
public:
	Node(int value, Node* node) {
		this->value = value;
		next = node;
	}

	void nextNode(Node*);
	Node* getNode();
	void setValue(int);
	int getValue();
};

class Stack {
private:
	Node* head=nullptr;
	int size;
public:
	void push(int);
	void pop();
	bool empty();
	int top();
};

int main() {
	int n;
	cin >> n;
	int m = 1;

	Stack stack;
	vector <char> result;
	

	for (int i{ 0 }; i < n; i++) {
		int x;
		cin >> x;

		while (m <= x) {
			stack.push(m);
			m++;
			result.push_back('+');
		}

		if (stack.top() == x) {
			stack.pop();
			result.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}

	}

		
	for (int i{ 0 }; i < result.size(); i++) {
			cout << result[i] << "\n";

		}
}
	
	


void Node::nextNode(Node* node)
{
	this->next = node;
}

Node* Node::getNode() {
	return next;
}

void Node::setValue(int value) {
	this->value = value;
}

int Node::getValue() {
	return value;
}

void Stack::push(int value) {
	Node* node = new Node(value, head);
	head = node;
	size++;
}

void Stack::pop() {
	Node* node = head;
	head = node->getNode();
	delete node;
	size--;

}

bool Stack::empty() {
	return size == 0;
}

int Stack::top() {
	return head->getValue();
}