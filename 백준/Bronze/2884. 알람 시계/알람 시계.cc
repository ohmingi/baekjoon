#include <iostream>
using namespace std;


int main()
{
	int x, y;

	cin >> x >> y;

	if (45 <= y and y<= 60)
	{
		cout << x <<" " << y - 45;
	}
	
	if (y<45 and x!=0)
	{
		cout << x-1 <<" "<< y+15;
	}
	
	if (y < 45 and x == 0)
	{
		cout << 23 << " " << y + 15;
	}

}