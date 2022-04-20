#include <iostream>


using namespace std;

int main() {
	
	int N, x, A;
	
	cin >> N >> x;
	
	while (N>0) {
		
		cin >> A;
		
		if (A < x) {
			cout << A << " ";
		}
		N--;
	}
}