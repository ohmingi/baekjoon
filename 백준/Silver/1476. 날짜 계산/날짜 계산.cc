#include <iostream>

using namespace std;

int main() {
	int E;
	0 <= E <= 15;

	int S;
	0 <= S <= 28;

	int M;
	0 <= M <= 19;

	int year{ 1 };

	cin >> E >> S >> M;

	while (1) {
		if ((year - E) % 15 == 0 && (year - S) %28== 0 && (year - M) % 19 == 0) {
			cout << year << endl;
			break;
		}
		else {
			year++;
		}
	}
}