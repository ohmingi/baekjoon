#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<string>st;

        for(int i = 0; i < n; i++){
            string str;
            cin >> str;
            st.push_back(str);
        }

        sort(st.begin(), st.end());

        bool b = false;

        for(int i = 0; i < n-1; i++){
            if(st[i+1].find(st[i]) == 0){
                b = true;
                cout << "NO\n";
                break;
            }

            if(b == 1) break;
        }

        if(b == 0) {
            cout << "YES\n";
        }
    }

    return 0;
}