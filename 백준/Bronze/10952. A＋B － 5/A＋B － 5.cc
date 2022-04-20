#include <iostream>


using namespace std;

int main() {
	
	int a, b;
	
	cin >> a >> b;
	
	while (b<10) {
		if (a == 0 and b == 0) {
			break;
		}
		cout << a + b << "\n";
		
		cin >> a >> b;
	}
}