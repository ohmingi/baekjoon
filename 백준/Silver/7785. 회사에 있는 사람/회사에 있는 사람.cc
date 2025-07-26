#include <iostream>
#include <map>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	map<string,string> m;
	
	while(n--){
		string str;
		string str1;
		cin >> str >> str1;
		m[str] = str1;
	}
	
	for(auto a = m.rbegin() ; a != m.rend() ; a++){
		if(a->second == "enter"){
			cout << a->first << "\n";
		}
	}
}