#include <iostream>
#include <string>
#include <unordered_set>
#include <set>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	
	unordered_set<string> s1;
	set<string> s2;
	
	while(n--){
		string str;
		cin >> str;
		
		s1.insert(str);
	}
	
	int count = 0;
	
	while(m--){
		string str;
		cin >> str;
		
		if(s1.find(str) != s1.end()){
			s2.insert(str);
			count++;
		}
	}
	
	cout << count << "\n";
	
	for(auto a : s2){
		cout << a << "\n";
	}
}