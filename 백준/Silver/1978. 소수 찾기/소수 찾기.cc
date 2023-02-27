#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int count{ 0 };

	while (n--) {
		int num;
		cin >> num;
		bool fact = true;

		if (num != 1) {
			for (int i{ 2 }; i < num; i++) {
				if ((num % i) == 0) {
					fact = false;
					break;
				}

			}


			if (fact == true) {
				count++;
			}
		}
	}

	cout << count;
}