#include <iostream>
#include <vector> 
#include <stack>

using namespace std;

int main(){
	stack<pair<int,int>> st;
	
	int n;
	cin >> n;
	
	int sum = 0;
	
	while(n--){
		int c,a,t;
		cin >> c;
		
		
		if(c == 1){
			cin >> a >> t;
		
			if(t == 1) {
				sum += a;
				continue;
			}
			st.push({a,t-1});
		}
		else{
			if(st.empty()) continue;
		
			if(st.top().second == 1){
				sum += st.top().first;
				st.pop();
			}
			else{
				st.top().second--;
			}
		}
	}
	
	cout << sum;
}