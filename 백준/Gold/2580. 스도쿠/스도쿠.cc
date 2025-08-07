#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int,int>> v;
int n[10][10];
bool finished;

bool check(int num,int x, int y){
    int x_x = ((x - 1) / 3) * 3 + 1;
    int y_y = ((y - 1) / 3) * 3 + 1;

    for(int i = 0; i < 3; i++){
        for(int t = 0; t < 3; t++){
            if(n[x_x + i][y_y + t] == num) return false;
        }
    }

    for(int i = 1; i <= 9; i++){
        if(n[i][y] == num) return false;
        if(n[x][i] == num) return false;
    }

    return true;

}

void dfs(int idx){
    if(finished) return;
    
    if(idx == v.size()){
        for(int i = 1; i < 10; i++){
            for(int t = 1; t < 10; t++){
                cout << n[i][t] <<" ";
            }
            cout << "\n";
        }
        finished = true;
        return;
    }

    int x = v[idx].first;
    int y = v[idx].second;

    for(int i = 1; i <= 9; i++){
        if(check(i,x,y)){
            n[x][y] = i;
            dfs(idx + 1);
            n[x][y] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i < 10; i++){
        for(int t = 1; t < 10; t++){
            cin >> n[i][t];
            if(n[i][t] == 0) {
                v.push_back(make_pair(i,t));
            }
        }
    }

    dfs(0);

}
