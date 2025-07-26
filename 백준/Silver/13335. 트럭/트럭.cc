#include <iostream>
#include <vector>

int N[1001]{0};

using namespace std;

int main(){
	int n,w,l;
	
	cin >> n >> w >> l;
	
	vector<int> v;
	
	while(n--){
		int a;
		cin >> a;
	
		v.push_back(a);
	}
	
	int sum = 0;
	int size = 0;
	int count = 0;
	
	while(!v.empty()){
		if(N[1] != 0){
			size--;
		}
		sum -= N[1];
		
		for(int i = 1 ; i < w; i++){
			N[i] = N[i+1];
		}
		
		if(size < w && sum + v.front() <= l){
			N[w] = v.front();
			sum += v.front();
			size++;
			v.erase(v.begin());
		}
		else{
			N[w] = 0;
		}
		
		count++;
	}
	
	cout << count + w;
}