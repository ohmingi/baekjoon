#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(){
	int n;
	cin >> n;
	cin.ignore();
	
	vector<vector<string>> v;
	
	for(int i = 0; i < n; i++){
		string str;
		getline(cin, str);
		
		istringstream ss(str);
		string word;
		
		v.push_back(vector<string>());
		
		while(ss >> word){
			v[i].push_back(word);
		}
	}
	
	string str;
	getline(cin, str);
		
		
	istringstream ss(str);
	string word;
	
	bool b = true;
	
	while(ss >> word){
		b = true;
	
		for(int i = 0; i < n; i++){
			if(v[i].front() == word){
				v[i].erase(v[i].begin());
				b = false;
			}
		}
		
		if(b == true){
			cout << "Impossible";
			return 0;
		}
		
	}
	
	for (int i = 0; i < n; i++) {
        if (!v[i].empty()) {
            cout << "Impossible";
            return 0;
      }
	}
	
	cout << "Possible";
}