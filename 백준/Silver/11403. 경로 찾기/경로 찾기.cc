#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int graph[101][101];
int result[101][101];
bool visited[101];

void dfs_matrix(int current_node) {
    for (int next_node = 1; next_node <= n; ++next_node) {
        if (graph[current_node][next_node] == 1 && !visited[next_node]) {
            visited[next_node] = true;
            dfs_matrix(next_node);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        
        dfs_matrix(i);

        for (int j = 1; j <= n; j++) {
            if (visited[j]) {
                result[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}