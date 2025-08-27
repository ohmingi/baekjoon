#include <iostream>
#include <algorithm>
#define mm 101

using namespace std;

int m,n,k;
int Count = 0;

int grid[mm][mm];
bool visited[mm][mm];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool check(int x, int y){
    return 0 <= x && x < m && 0 <= y && y < n;
}

void dfs(int x,int y){
    visited[x][y] = 1;
    Count++;
    //cout << "g\n";
    
    for(int i=  0; i < 4 ; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if(check(new_x,new_y) && !visited[new_x][new_y] && grid[new_x][new_y] == 0){
            dfs(new_x,new_y);
        }
    }
}

int main() {
    cin >> m >> n >> k;
    vector<int> v;

    int count1 = 0;
    
    for(int i = 0; i < k; i++){
        int x,y,x1,y1;
        cin >> x >> y >> x1 >> y1;

        for(int t = x; t < x1; t++){
            for(int a = y; a < y1; a++){
                grid[a][t] = 1;
            }
        }
    }

    for(int i = 0; i < m; i++){
            for(int t = 0; t < n; t++){
                //cout << grid[i][t] << " ";
                if(grid[i][t] == 0 && !visited[i][t]){
                    dfs(i,t);
                    count1++;
                    v.push_back(Count);
                }
                Count = 0;
            }
        //cout << "\n";
    }

    sort(v.begin(),v.end());

    cout << count1 << "\n";
    for(auto a : v){
        cout << a << " ";
    }
}