#include <iostream>

using namespace std;

int main()
{
	int a(0), b(0);
	  
	cin >> a;
	cin >> b;
	
	int b1 = b/100;
	int b2 = (b - b1 * 100) / 10;
	int b3 = (b - (b1 * 100) - (b2 * 10));
		
		cout << a * b3 << endl;
		cout << a * b2 << endl;
		cout << a * b1 << endl;
		cout << a * b << endl;
   return 0;
}