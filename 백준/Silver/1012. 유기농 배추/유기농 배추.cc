#include <iostream>
#include <cstring>

using namespace std;

int m,n,k;
int graph[50][50];
bool visited[50][50];

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool check(int x, int y){
    return x >= 0 && x < m && y >= 0 && y < n;
}

void dfs(int x, int y){
    visited[x][y] = 1;

    for(int i = 0; i < 4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];

        if(!visited[newx][newy] && check(newx, newy) && graph[newx][newy] == 1){
            dfs(newx,newy);
        }
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> m >> n >> k;
        while(k--){
            int a, b;
            cin >> a >> b;
            graph[a][b] = 1;
        }

        int c = 0;

        for(int x = 0; x < m; x++){
            for(int y = 0; y < n; y++){
                if(!visited[x][y] && graph[x][y] == 1){
                    dfs(x,y);
                    c++;
                }
            }
        }

        cout << c << "\n";

        memset(visited, 0, sizeof(visited));
        memset(graph, 0, sizeof(graph));
    }
}