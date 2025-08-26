#include <iostream>

using namespace std;

int graph[1001][1001];
bool visited[1001];
int n,m;

void dfs(int x){
    visited[x] = 1;

    for(int i = 1; i <= n; i++){
        if(visited[i] == 0 && graph[x][i] == 1){
            dfs(i);
        }
    }
}

int main(){
    cin >> n >> m;

    while(m--){
        int a,b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    int c = 0;

    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
            dfs(i);
            c++;
        }
    }

    cout << c;
}