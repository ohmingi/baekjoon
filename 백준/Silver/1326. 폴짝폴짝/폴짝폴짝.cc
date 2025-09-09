#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> jump(N + 1);
    for (int i = 1; i <= N; i++) cin >> jump[i];

    int start, goal;
    cin >> start >> goal;

    vector<int> dist(N + 1, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next = cur + jump[cur]; next <= N; next += jump[cur]) {
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }

        for (int next = cur - jump[cur]; next >= 1; next -= jump[cur]) {
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }

    cout << dist[goal] << "\n";
    return 0;
}
