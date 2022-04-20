#include <iostream>


using namespace std;

int main() {
	
	int a, b;
	int count{ 0 };
	cin >> a;
	b = a;
	
	do {
		
		a = (a % 10) * 10 + ((a/10)+(a % 10)) % 10;

		count++;
	
	} while (a!=b);

	cout << count;
}