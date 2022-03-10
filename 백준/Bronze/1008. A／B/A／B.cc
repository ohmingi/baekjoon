#include <iostream>

int main()
{
	double a, b;
	
	std::cout.precision(15);
	std::cin >> a >> b;
	std::cout << a / b;
	return 0;
}