#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a;
	
	int i{1};

	while(a>0){
		cin >> b >> c;
		cout << "Case #"<< i<< ": "<< b+c << "\n";
		a--;
		i++;
	}
}