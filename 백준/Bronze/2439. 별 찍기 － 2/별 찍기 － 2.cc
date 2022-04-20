#include <iostream>


using namespace std;

int main() {
	
	int i;
	
	cin >> i;
	int c = i;

	for (i; i > 0; i--) {
		for (int space{ 1 }; space < i; space++) {
			cout << " ";
		}

		for (int star{c}; star >= i; star--) {
			cout <<"*";
		}
		cout << "\n";
	}
}