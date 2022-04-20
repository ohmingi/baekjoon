#include <iostream>

using namespace std;

int main() {
	int a;
	cin >> a;

	while (a>0) {
		int b, c;
		cin >> b >> c;
		cout << b + c << endl;
		--a;
	}
}
