#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	
	vector<int> v;
	
	for(int i = 1; i <= n ; i++ ){
		v.push_back(i);
	}
	
	cout << '<' <<v[k-1];
	v.erase(v.begin() + k-1);
	int step = k-1;
	
	while(!v.empty()){
		step += k - 1;
		if(step >= v.size()) step %= v.size();
		
		cout << ", " << v[step];
		
		v.erase(v.begin() + step);
	}
	
	cout << '>';
	
}