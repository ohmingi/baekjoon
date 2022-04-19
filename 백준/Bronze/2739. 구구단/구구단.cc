#include <iostream>

using namespace std;

int main() {
	int counter{ 1 };
	int a;
	cin >> a;
	
	while (counter <= 9) {
		cout << a << " * " << counter << " = " << a * counter << endl;
		counter++;
	}
}