#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int n,m,k;
int c = 0;
int ma = -1;
vector<int> v;
vector<vector<int>> pV;

void check(vector<int> comb){
    unordered_set<int> s(comb.begin(), comb.end());

    for(int i = 0; i < m; i++){
        bool b = true;

        for(int t = 0; t < k; t++){
            if(s.count(pV[i][t]) == 0){
                b = false;
                continue;
            }
        }

        if(b == true) c++;
    }
}

void dfs(int sta, int dep){
    if(dep == n){
        c = 0;
        check(v);
        if(ma < c) ma = c;
        return;
    }

    for(int i = sta; i <= 2*n; i++){
        v.push_back(i);
        dfs(i + 1, dep + 1);
        v.pop_back();
    }
}

int main(){
    cin >> n >> m >> k;

    pV.assign(m, vector<int>(k,0));

    for(int i = 0; i < m; i++){
        for(int t = 0; t < k; t++){
            cin >> pV[i][t];
        }
    }

    dfs(1,0);

    cout << ma;
}