#include <iostream>
#include <string>

using namespace std;

class Node {
private:
	int value;
	Node* next;
public:
	Node(int value, Node* node = nullptr) {
		this->next = node;
		this->value = value;
	};
	int getData();
	Node* getNext();
	void setData(int);
	void setNext(Node*);
};

class Stack {
public:
	bool empty();
	int size();
	int top();
	void push(int);
	int pop();
	/*void display();*/
private:
	Node* TopNode;
	int datasize=0;
};

int main() {

	Stack arr;
	int n;
	string str;
	cin >> n;

	while (n--) {
		cin >> str;
		if (str == "push") {
			int value;
			cin >> value;
			arr.push(value);
		}
		else if (str=="pop") {
			cout <<arr.pop()<<"\n";
		}
		
		else if (str=="size") {
			cout << arr.size()<<"\n";
		}

		else if (str=="empty") {
			cout << arr.empty()<<"\n";
		}
		else if (str=="top") {
			cout << arr.top()<<"\n";
		}
	}


}


int Node::getData() {
	return value;
}

Node* Node::getNext() {
	return next;
}

void Node::setData(int data) {
	this->value = data;
}

void Node::setNext(Node* node) {
	this->next = node;
}




bool Stack::empty() {
	if (datasize == 0) {
		return 1;
	}
	else {
		return 0;
	}
	
}

int Stack::size() {
	return datasize;
}

int Stack::top() {
	if (empty()) {
		return -1;
	}
	return TopNode->getData();
}

void Stack::push(int data) {
	Node* node = new Node(data, TopNode);
	TopNode = node;
	datasize++;
}

int Stack::pop() {
	if (datasize == 0) {
		return -1;
	}
	else {
		int topvlaue = top();
		Node* node = TopNode;
		TopNode = node->getNext();
		delete node;
		datasize--;
		return topvlaue;
	}
	
}



