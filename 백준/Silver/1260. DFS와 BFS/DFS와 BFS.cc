#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n,m,v;
int graph[1001][1001];
bool visited[1001];

void dfs(int x){
    visited[x] = 1;
    cout << x << " ";

    for(int i = 1; i <= n; i++){
        if(!visited[i] && graph[x][i] == 1){
            dfs(i);
        }
    }
}

void bfs(int x){
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while(!q.empty()){
        cout << q.front() << " ";
        int qq = q.front();
        q.pop();

        for(int i = 1; i <= n; i++){
            if(!visited[i] && graph[qq][i] == 1){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    cin >> n >> m >> v;

    while(m--){
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    dfs(v);
    cout << "\n";
    memset(visited, false, sizeof(visited));
    bfs(v);
}