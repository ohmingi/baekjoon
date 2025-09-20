#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<pair<int,int>> v;
    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    
      sort(v.begin(), v.end(), [](const pair<int,int> &a, const pair<int,int> &b){
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    int f;
    f = v[0].second;
    int cnt = 1;

    for(int i = 1; i < n; i++){
        if(v[i].first >= f){
            f = v[i].second;
            cnt++;
        }
    }

    cout << cnt;
}