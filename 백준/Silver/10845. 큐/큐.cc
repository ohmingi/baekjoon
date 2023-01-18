#include <iostream>

using namespace std;

class Node {
private:
	Node* next;
	int value;
public:
	Node(int value, Node* node) {
		this->value = value;
		this->next = node;
	}

	int getData();
	void setData(int);
	void setNext(Node*);
	Node* getNext();
};

class Queue {
private:
	Node* Front;
	Node* Rear;
	int datasize=0;
public:
	void push(int);
	int pop();
	int size();
	bool empty();
	int front();
	int back();
	

};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	string str;

	Queue queue;

	while (n--) {
		cin >> str;
		if (str == "push") {
			int value;
			cin >> value;
			queue.push(value);
		}

		else if (str=="front") {
			cout << queue.front() << "\n";
		}

		else if (str=="back") {
			cout << queue.back() << "\n";
		}

		else if (str=="size") {
			cout << queue.size() << "\n";
		}

		else if (str=="empty") {
			cout << queue.empty() << "\n";
		}

		else if (str=="pop") {
			cout << queue.pop() << "\n";
		}
	}
}

int Node::getData() {
	return value;
}

Node* Node::getNext() {
	return next;
}

void Node::setData(int value) {
	this->value = value;
}

void Node::setNext(Node* node) {
	next = node;
}

void Queue::push(int value) {
	Node* node = new Node(value, nullptr);	

	if (Front == nullptr) {
		Front = node;
		Rear = node;

	}
	else {
		Rear->setNext(node);
		Rear = node;
	}
	datasize++;
}

int Queue::pop() {
	if (datasize == 0) {
		return -1;
	}
	else {
	int grade = Front->getData();
	Node* node = Front;
	Front = Front->getNext();
	delete node;
	datasize--;
	return grade;
	
	}
	
	
}

int Queue::size() {
	return datasize;
}

bool Queue::empty() {
	return datasize == 0;
}

int Queue::front() {
	if (!empty()) {
	return Front->getData();
	}
	else {
		return -1;
	}

}

int Queue::back() {
	if (!empty()) {
		return Rear->getData();
	}
	else {
		return -1;
	}
}
