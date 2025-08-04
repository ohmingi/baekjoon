#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N[21][21];
int n;
int Min = 201;
int c[2];
vector<int> v;
vector<int> v1;
vector<int> vv;
vector<int> vv1;

void cal(vector<int> team,int &sum) {
    for (int i = 0; i < team.size(); i++) {
        for (int t = 0; t < team.size(); t++) {
            if (i == t) continue;
            sum += N[team[i]][team[t]];
        }
    }
}


void dfs(int sta, int dep){
    if(dep == n/2){
        v1.clear(); vv.clear(); vv1.clear();
        c[0] = c[1] = 0;

        for(int i = 1; i <= n; i++){
            if(find(v.begin(), v.end(), i) == v.end()) vv.push_back(i);
        }
  
        cal(v,c[0]);
        cal(vv,c[1]);
        Min = min(Min, abs(c[0] - c[1]));
        return;
    }

    for(int i = sta; i <= n; i++){
        v.push_back(i);
        dfs(i + 1, dep + 1);
        v.pop_back();
    }
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int t= 1; t <= n; t++){
            cin >> N[i][t];
        }
    }

    dfs(1,0);
    cout << Min;
}