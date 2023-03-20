#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n,m;
vector<int>v;
int t1, t2;

bool func(int a)
{

	int low = 0;
	int high = v.size() - 1;

	while (low <= high)
	{	
		int mid = (low + high) / 2;	
		
		if (v[mid] == a)	
			return true;

		if (v[mid] < a)	
			low = mid+1;	
		else if (v[mid] > a)
			high = mid-1;

	}

	return false;
}


int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> t1;
		v.push_back(t1);	
	}

	sort(v.begin(), v.end());	


	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> t2;	

		if (func(t2))
			cout << "1" << '\n';	
		else
			cout << "0" << '\n';	
		
	}

	return 0;
}