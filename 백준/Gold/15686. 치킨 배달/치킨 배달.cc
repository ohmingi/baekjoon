#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n,m;
int N[51][51];
vector<pair<int,int>> v;
vector<pair<int,int>> v1;
vector<pair<int,int>> house;
int mi = 1e9;

void dfs1(int sta){
    if(v1.size() == m){
        int sum = 0;
        for(auto a : house){
            int mmin = 1e9;
            for(auto b : v1){
                int c = abs(a.first - b.first) + abs(a.second - b.second);
                mmin = min(c,mmin);
            }
            sum += mmin;
        }
        
        if(mi > sum) mi = sum;
        return;
    }

    for(int i = sta; i < v.size(); i++){
        v1.push_back(v[i]);
        dfs1(i + 1);
        v1.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int t = 1; t <= n; t++){
            cin >> N[i][t];
            if(N[i][t] == 2) v.push_back(make_pair(i,t));
            if(N[i][t] == 1) house.push_back(make_pair(i,t));
        }
    }

    dfs1(0);

    cout << mi;

}