#include <iostream>

using namespace std;

int n;
int graph[11][11];
bool visited[11];
int mi = 1e9;

void dfs(int start,int cur, int cnt, int res){
    if(res > mi) return;

    if(cnt == n){
        if(graph[cur][start] != 0) mi = min(mi,res + graph[cur][start]);
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i] && graph[cur][i] != 0){
            res += graph[cur][i];
            visited[i] = true;
            dfs(start, i, cnt + 1, res);
            visited[i] = false;
            res -= graph[cur][i];
        }
    }
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int t = 1; t <= n; t++){
            cin >> graph[i][t];
        }
    }

    for(int i = 1; i <= n; i++) {
        fill(visited, visited + n, false);
        visited[i] = true;
        dfs(i, i, 1, 0);
    }

    cout << mi;
}