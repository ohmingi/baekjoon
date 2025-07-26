#include <iostream>
#include <vector> 
#include <stack>

using namespace std;

int main(){
	stack<int> st;
	
	int n;
	cin >> n;
	
	int c = 0;
	
	st.push(n+1);
	
	while(n--){
		int a;
		cin >> a;
		
		if(c + 1 == a) {
			c = a;
		}
		else if(st.top() > a){
			st.push(a);
		}
		else if(st.top() == c + 1){
			while(st.top() == c + 1){
				c = st.top();
				st.pop();
			}
			if(st.top() > a){
				st.push(a);
			}
			else{
				cout << "Sad";
				return 0;
			}
		}
		else{
			cout << "Sad";
			return 0;
		}
	}
	
	cout << "Nice";
}