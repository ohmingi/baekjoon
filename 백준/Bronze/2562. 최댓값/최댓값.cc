#include <iostream>


using namespace std;

int main() {

	int a[9];

	for (int i{ 0 }; i < 9; i++) {
		int score;
		cin >> score;
		a[i] = score;
	}

	int big = a[0];

	for (int i{ 1 }; i < 9; i++) {
		if (big < a[i]) {
			big = a[i];
		}
	}

	
    int count{ 0 };
	for (int i{ 0 }; i < 9;i++) {
		if (a[i] == big) {
			count = i+1;
		}
	}

	cout << big << "\n" << count;
}