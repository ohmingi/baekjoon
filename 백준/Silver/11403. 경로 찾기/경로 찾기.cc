#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<vector<int>> v;
bool visited[101];
int graph[101][101];

void dfs(int node, int aw, int f){
    visited[node] = 1;

    for(int i = 1; i <= n; i++){
        if(v[node][i] == 1 && i == aw) graph[i][i] = 1;
        if(v[node][i] == 1 && !visited[i]){
            if(i == f) {
                graph[aw][f] = 1;
                return;
            }
            dfs(i, aw, f);
        }
    }
}

int main(){
    cin >> n;
    v.assign(n+1, vector<int>(n+1));

    for(int i = 1; i <= n; i++){
        for(int t = 1; t <= n; t++){
            cin >> v[i][t];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int t = 1; t <= n; t++){
            dfs(i,i,t);
            memset(visited, 0, sizeof(visited));
            cout << graph[i][t] << " ";
        }

        cout << "\n";
    }

}