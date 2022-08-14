#include <iostream>

using namespace std;

int a[42]{};


int main() {
	for (size_t t{ 0 }; t < 10; t++) {
		int b;
		cin >> b;
		a[b % 42]++;
	}
	
	int result{ 0 };

	for (int v : a) {
		if (v > 0) {
			result++;
		}
	}
	cout << result;

}