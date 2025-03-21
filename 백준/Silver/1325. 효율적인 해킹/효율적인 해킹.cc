#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<int> adj[10001]; // 인접 리스트 사용
bool visited[10001];    // 방문 체크 배열
int hackCount[10001];   // 각 노드가 해킹할 수 있는 컴퓨터 수

// BFS를 이용하여 해킹 가능한 개수를 계산
int bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int count = 1; // 자기 자신 포함

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int next : adj[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                count++;
            }
        }
    }
    return count;
}

int main() {
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a); // b를 해킹하면 a를 해킹 가능
    }

    int maxHacks = 0;
    vector<int> result;

    for (int i = 1; i <= n; i++) {
        fill(visited, visited + n + 1, false); // 매번 방문 배열 초기화
        hackCount[i] = bfs(i); // BFS 탐색 후 해킹 가능한 개수 저장

        if (hackCount[i] > maxHacks) {
            maxHacks = hackCount[i];
            result.clear();
            result.push_back(i);
        } else if (hackCount[i] == maxHacks) {
            result.push_back(i);
        }
    }

    sort(result.begin(), result.end());

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
