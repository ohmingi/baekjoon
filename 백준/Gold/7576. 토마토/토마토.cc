#include <iostream>
#include <queue>

using namespace std;

int n,m;
int graph[1000][1000];
bool visited[1000][1000];
int dep[1001][1001];
queue<pair<int,int>> q;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int res;
int zero = 0;

bool check(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(){
    while(!q.empty()){
        auto a = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = a.first + dx[i];
            int ny = a.second + dy[i];

            if(check(nx, ny) && !visited[nx][ny] && graph[nx][ny] == 0){
                q.push({nx,ny});
                visited[nx][ny] = 1;
                graph[nx][ny] = 1;
                res = dep[a.first][a.second] + 1;
                dep[nx][ny] = dep[a.first][a.second] + 1;
                zero++;
            }
        }
    }
}

int main(){
    cin >> m >> n;

    bool b = false;
    for(int i = 0; i < n; i++){
        for(int t = 0; t < m; t++){
            cin >> graph[i][t];
            if(graph[i][t] == 0) b = true;
            if(graph[i][t] == 1) {
                q.push({i,t});
                visited[i][t] = 1;
            }
            if(graph[i][t] != 0) zero++;
        }
    }

    

    if(b == false){
        cout << 0;
        return 0;
    }

    bfs();

    if(zero != m*n){
        cout << -1;
        return 0;
    }

    cout << res;
    //cout << "\n" << graph[1][0];

}