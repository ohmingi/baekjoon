#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<pair<int,int>> v;
	
	vector<int> vv;
	
	int n;
	cin >> n;
	
	for(int i = 1 ; i <= n ; i++){
		int a;
		cin >> a;
		v.push_back({i,a});
	}
	
	vv.push_back(v[0].first);
	
	int step = v[0].second;
	int curr = 0;

	
	while(!v.empty()){
		v.erase(v.begin() + curr);
		if(v.empty()) break;
	
			int size = v.size();
		
			if(step > 0) curr -= 1;
			
			curr += step;
			curr = curr % size;
			
			if(curr < 0) curr += v.size();
			
			
			vv.push_back(v[curr].first);
			step = v[curr].second;
	}
	
	for(int i = 0; i < vv.size() ; i++){
		cout << vv[i];
		if(i != vv.size() - 1){
			cout << " ";
		}
	}
}