#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    stack<pair<int,int>> st;
    vector<int> v;
    v.push_back(0);

    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        if(st.empty()){
            st.push({a,i});
        }
        else if(a > st.top().first){
            while(!st.empty() && st.top().first < a){
                st.pop();
            }
            if(st.empty()) v.push_back(0);
            else{
                v.push_back(st.top().second);
            }
            st.push({a,i});
        }
        else{
            v.push_back(st.top().second);
            st.push({a,i});
        }
    }

    for(int a : v){
        cout << a << " ";
    }
}