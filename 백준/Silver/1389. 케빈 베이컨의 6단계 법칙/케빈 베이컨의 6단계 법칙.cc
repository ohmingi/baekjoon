#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n,m;
int graph[101][101];
bool visited[101];
int dep[101];

void bfs(int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int a = q.front();
        q.pop();

        for(int i = 1; i <= n; i++){
            if(!visited[i] && graph[a][i] == 1){
                q.push(i);
                visited[i] = 1;
                dep[i] = dep[a] + 1;
            }
        }
    }
}

int main(){
    cin >> n >> m;

    while(m--){
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    int mi = 1e9;
    int res;
    
    for(int i = 1; i <= n; i++){
        int a = 0;
        bfs(i);
        for(int t = 1; t <= n; t++){
            if(i == t) continue;
            //cout << dep[t] << " ";
            a += dep[t];
        }
        memset(visited, 0, sizeof(visited));
        memset(dep, 0, sizeof(dep));        

       // cout << "\n";
        if(mi > a){
            res = i;
            mi = a;
        }   
    }

    cout << res;
    
}