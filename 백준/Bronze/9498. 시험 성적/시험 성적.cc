#include <iostream>

using namespace std;

int main()
{
	int a;
	cin >> a;
	
	if (100 >= a && a>= 90)
	{
		cout << "A";
	}
	if (89 >= a && a >= 80)
	{
		cout << "B";
	}
	if (79 >= a && a >= 70)
	{
		cout << "C";
	}
	if (69 >= a && a >= 60)
	{
		cout << "D";
	}
	if (59 >= a && a>= 0)
	{
		cout << "F";
	}
	
   return 0;
}