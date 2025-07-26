#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
   unordered_map<string,string> mp;

   int n,m;
   cin >> n >> m;

   string s1,s2;

   while(n--){
    cin >> s1 >> s2;
    mp[s1] = s2;
   }

   while(m--){
    cin >> s1;
    cout << mp[s1] << "\n";
   }

}
