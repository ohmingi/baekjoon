#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
		
	cin >> n;

	double *v = new double[n];

	for (int i{0}; i < n; i++) {
		cin >> v[i];		
	}
	
	sort(v,v+n);

	double big = v[n - 1];

	for (int i{ 0 }; i < n; i++) {
		v[i] = (v[i] /big) * 100;
	}

	double sum{0};
	double value;

	for (int i{ 0 }; i < n ; i++) {
		sum += v[i];
	}

	value = sum / n;

	cout << value;
}