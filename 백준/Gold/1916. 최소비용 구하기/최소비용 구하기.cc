#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[1001];
int dist[1001];

void dijkstra(int v) {
  fill(dist, dist + 1001, 1e9);
  dist[v] = 0;

  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

  pq.push(make_pair(v, 0));

  while (!pq.empty()) {
    int curr = pq.top().first;
    int d = pq.top().second;
    pq.pop();

    if (dist[curr] < d) {continue;}

    for (auto a : adj[curr]) {
      int next = a.first;
      int cost = a.second;

      if (dist[curr] + cost < dist[next]) {
        dist[next] = dist[curr] + cost;
        pq.push(make_pair(next, dist[next]));
      }
    }
  }




}

int main() {
  int N,M;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int a,b,c;
    cin >> a >> b >> c;

    adj[a].push_back(make_pair(b, c));
  }

  int a, b;
  cin >> a >> b;

  dijkstra(a);

  cout << dist[b];

}