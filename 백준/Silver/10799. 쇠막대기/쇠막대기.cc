#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	stack<char> s;
	string str;
	cin >> str;
	
	int result = 0;
	bool b = true;
	
	for(int i = 0 ; i < str.size() ; i++){
		if(str[i] == '('){
			s.push(str[i]);
			b = true;
		}
		else{
			s.pop();
			if(b == false){
				result += 1;
			}
			else{
				result += s.size();
			}
				
			b = false;
		}
		
	}
	
	cout << result;
	
}