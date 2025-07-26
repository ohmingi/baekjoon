#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	unordered_set<string> s;
	
	int n;
	cin >> n;
	
	int count = 0;
	
	while(n--){
		string str;
		cin >> str;
		if(str == "ENTER"){
			s.clear();
			continue;
		}
		
		if(s.find(str) == s.end()){
			count++;
		}
		
		s.insert(str);
	}
	
	cout << count;
}