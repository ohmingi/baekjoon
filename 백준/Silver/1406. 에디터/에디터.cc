#include <iostream>
#include <list>

using namespace std;

int main(){

	string str;
	cin >> str;
	
	int n;
	cin >> n;
	
	list<char> v;
	
	for(int i=0;i<str.size();i++){
		v.push_back(str[i]);
	}
	
	auto it = v.end();
	
	while(n--){	
		char c;
		cin >> c;
		
		if(c == 'L'){
			if(it == v.begin()) continue;
			--it;
		}
		else if(c == 'D'){
			if(it == v.end()) continue;
			it++;
		}
		else if(c == 'B'){
			if(it == v.begin()) continue;
			--it;
			it = v.erase(it);
		}
		else{
			char a;
			cin >> a;
			v.insert(it,a);
		}
	}
	
	for(auto i : v){
		cout << i;
	}
	
}